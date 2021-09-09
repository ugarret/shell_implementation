#include "../mini.h"

void	canonical_input_on(t_history *tmp)
{
	tcgetattr(0, &tmp->term);
	tmp->term.c_lflag |= ECHO;
	tmp->term.c_lflag |= ICANON;
	tcsetattr(0, TCSANOW, &tmp->term);
	tgetent(0, tmp->term_name);
}

void	canonical_input_off(t_history *tmp)
{
	tcgetattr(0, &tmp->term);
	tmp->term.c_lflag &= ~(ECHO);
	tmp->term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &tmp->term);
	tgetent(0, tmp->term_name);
}

void	canonical_input_on_with_exit(struct termios *term, int error)
{
	my_putendl_fd("exit", 1);
	tcgetattr(0, term);
	term->c_lflag |= (ECHO);
	term->c_lflag |= (ICANON);
	tcsetattr(0, TCSANOW, term);
	exit(error);
}
