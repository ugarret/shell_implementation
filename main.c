#include "mini.h"

static void	history_initialization(t_history *history)
{
	history->index = history->max;
	if (history->max > 0)
		return ;
	history->max = 0;
	history->arr = (char **)malloc(sizeof(char *) * 2);
	history->arr[history->max] = (char *) my_calloc(1, sizeof(char));
	history->arr[history->max + 1] = NULL;
}

static char	**new_arr(char **old_arr, char *new_param, int len_arr)
{
	char	**new_arr;

	new_arr = (char **)malloc(sizeof(char *) * (len_arr + 2));
	if (!new_arr || !new_param)
		return (NULL);
	new_arr[len_arr] = new_param;
	new_arr[len_arr + 1] = NULL;
	while (--len_arr >= 0)
		new_arr[len_arr] = old_arr[len_arr];
	free(old_arr);
	return (new_arr);
}

static void	create_history(t_history *hist, char **format)
{
	hist->del_tmp = my_strchr(hist->arr[hist->index], '\n');
	if (hist->del_tmp)
		*hist->del_tmp = '\0';
	hist->max++;
	hist->del_tmp = hist->arr[hist->max - 1];
	hist->arr[hist->max - 1] = my_strdup(hist->arr[hist->index]);
	if (hist->del_tmp)
		free(hist->del_tmp);
	hist->arr = new_arr(hist->arr, my_calloc(1, sizeof(char)), hist->max);
	*format = hist->arr[hist->index];
}

static void	get_new_symbol(t_history *history)
{
	int	len;

	while (my_strncmp(history->buf, "\4", 1))
	{
		history->was_read = read(0, history->buf, 9);
		history->buf[history->was_read] = '\0';
		len = my_strlen(history->arr[history->index]);
		if (!my_strncmp(history->buf, "\4", 1) && len > 0)
			history->buf[0] = '\0';
		if (!my_strncmp(history->buf, "\e[A", 3))
			arrow_to_up(history);
		else if (!my_strncmp(history->buf, "\e[B", 3))
			arrow_to_down(history);
		else if (!my_strncmp(history->buf, "\177", 1))
			my_backspace(history);
		else if (!my_strncmp(history->buf, "\e[C", 3) || \
			!my_strncmp(history->buf, "\e[D", 3))
			continue ;
		else
			write_new_symbol(history);
		if (!my_strncmp(history->buf, "\n", 1))
			break ;
	}
}

int	main(int ac, char **av, char **env)
{
	t_matur				*matur;
	char				*str;
	static t_history	tmp;

	matur = (t_matur *) my_calloc(1, sizeof(t_matur));
	get_env(env, matur);
	if (ac != 1 && av[1] != NULL)
		my_putstr_fd("Я торжественно решил игнорировать твои аргументы\n", 1);
	signal(SIGINT, signal_for_new_line);
	signal(SIGQUIT, signal_exit_from_cat);
	while (1)
	{
		write (1, "welcome to shell> ", 18);
		history_initialization(&tmp);
		canonical_input_off(&tmp);
		tputs(save_cursor, 1, my_putchar);
		get_new_symbol(&tmp);
		if (!my_strncmp(tmp.buf, "\4", 1))
			canonical_input_on_with_exit(&tmp.term, matur->error);
		canonical_input_on(&tmp);
		create_history(&tmp, &str);
		parser(str, matur);
	}
}
