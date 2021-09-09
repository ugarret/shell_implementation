#include "../mini.h"

void	my_backspace(t_history *history)
{
	int	len;

	len = my_strlen(history->arr[history->index]);
	if (!(len > 0))
		return ;
	tputs(cursor_left, 1, my_putchar);
	tputs(tigetstr("ed"), 1, my_putchar);
	history->arr[history->index][len - 1] = '\0';
}

void	write_new_symbol(t_history *history)
{
	char	*old_str;

	old_str = history->arr[history->index];
	write(1, history->buf, history->was_read);
	history->arr[history->index] = my_strjoin(old_str, history->buf);
	if (old_str)
		free(old_str);
}

void	arrow_to_up(t_history *history)
{
	tputs(restore_cursor, 1, my_putchar);
	tputs(tigetstr("ed"), 1, my_putchar);
	if (history->index > 0)
	{
		history->index--;
		my_putstr_fd(history->arr[history->index], 1);
	}
	else
		my_putstr_fd(history->arr[history->index], 1);
}

void	arrow_to_down(t_history *history)
{
	tputs(restore_cursor, 1, my_putchar);
	tputs(tigetstr("ed"), 1, my_putchar);
	if (history->index < history->max)
	{
		history->index++;
		my_putstr_fd(history->arr[history->index], 1);
	}
	else
		my_putstr_fd(history->arr[history->index], 1);
}
