#ifndef MINI_H
# define MINI_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <term.h>
# include <termios.h>
# include "libmy/libmy.h"

typedef struct s_lstc
{
	t_list	*lst;
	int		count;
}				t_lstc;

typedef struct s_redir
{
	char		*input;
	t_list		*output;
	int			error;
}				t_redir;

typedef struct s_list_env
{
	char				*key;
	char				*value;
	struct s_list_env	*next;
	struct s_list_env	*previous;
}						t_list_env;

typedef struct s_history
{
	struct termios	term;
	char			*term_name;
	int				was_read;
	char			buf[10];
	char			**arr;
	char			*del_tmp;
	int				index;
	int				max;
}					t_history;

typedef struct s_matur
{
	char			**mass;
	int				i;
	t_list_env		*env;
	int				error;
	int				flag_pipe;
	struct termios	term;
}					t_matur;

/*Функции для парсера*/
t_matur		*parser(char *str, t_matur *matur);
char		*my_strn(char *str, int len);
void		get_env(char **env, t_matur *matur);
char		*double_quotes(char **str, t_matur *matur);
char		*skip_space(char *str);
char		*single_quotes(char **str);
char		*my_list(char **str);
char		*env_variables(char **str, t_matur *matur);
char		*pars_select(char **str, t_matur *matur);
void		redir_pars(char **str, t_matur *matur, t_lstc *collector);
char		*strjoin_free(char *str1, char *str2);
void		add_to_lst(t_lstc *lstc, void *p);
void		clear_lst(t_lstc *lstc);
void		lst_free(t_lstc *lstc);
void		list_processing(t_matur *matur, t_lstc *cll_l, \
											t_lstc *pipe_l, char **s);
void		allocate_mem(t_matur *matur, t_lstc *collector);

/*Функции для команд*/
void		builtin_function_or_no(t_matur *matur);
void		my_echo(t_matur *matur);
void		my_unset(t_matur *matur);
void		my_env(t_matur *matur);
void		my_exit(t_matur *matur);
void		my_export(t_matur *matur);
void		my_pwd(t_matur *matur);
void		my_cd(t_matur *matur);
int			validation_of_arguments(char *str, t_matur *matur);
void		my_puterror(char *bash, char *argument, char *my_error);
void		work_with_pipe(int count_pipe, t_list **commands, t_matur *matur);
void		work_with_redirect(t_redir *redir, t_matur *matur);

/*Функции для работы с листами двусвязного списка*/
t_list_env	*new_element(char *key, char *value);
int			add_element(t_list_env **list, t_list_env *new);
int			delete_element_from_list(t_list_env **list, char *key);
int			replace_value(t_list_env **list, char *key, char *new);
char		*search_element_in_list_on_key(t_list_env **list, char *key);
t_list_env	*sort_elements_of_list(t_list_env *list);
int			add_value(t_list_env **list, char *key, char *new);
char		**list_to_arr(t_list_env **list);

/*Функции для работы с терминалом*/
void		canonical_input_off(t_history *tmp);
void		canonical_input_on(t_history *tmp);
void		my_backspace(t_history *history);
void		write_new_symbol(t_history *history);
void		arrow_to_up(t_history *history);
void		arrow_to_down(t_history *history);
void		canonical_input_on_with_exit(struct termios *term, int error);
void		signal_for_new_line(int sig);
void		signal_exit_from_cat(int sig);

#endif
