#include "../mini.h"

void	lst_err_check(t_matur *matur, t_lstc *cll_l, t_lstc *pipe_l, char **s)
{
	if (*(skip_space(*s + 1)) == ';' || *(skip_space(*s + 1)) == '|')
	{
		if (*(*s + 1) == ';')
			my_puterror("syntax error near unexpected token", NULL, "';;'");
		else if (*(*s + 1) == '|')
			my_puterror("syntax error near unexpected token", NULL, "'|'");
		else
			my_puterror("syntax error near unexpected token", NULL, "';'");
		matur->error = 258;
		*(*s + 1) = 0;
		clear_lst(cll_l);
		clear_lst(pipe_l);
	}
}

void	list_processing(t_matur *matur, t_lstc *cll_l, t_lstc *pipe_l, char **s)
{
	if (cll_l->count != 0)
	{
		allocate_mem(matur, cll_l);
		if (**matur->mass)
			lst_err_check(matur, cll_l, pipe_l, s);
		else if (**s == ';')
		{
			if (*(*s + 1) == ';')
				my_puterror("syntax error near unexpected token", NULL, "';;'");
			else
				my_puterror("syntax error near unexpected token", NULL, "';'");
			matur->error = 258;
			*(*s + 1) = 0;
		}
		add_to_lst(pipe_l, matur->mass);
		if (pipe_l->count == 1)
			builtin_function_or_no(matur);
		else
			work_with_pipe(pipe_l->count, &pipe_l->lst, matur);
	}
	clear_lst(cll_l);
	clear_lst(pipe_l);
}
