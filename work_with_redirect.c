#include "mini.h"

static void	substitution_of_file_descriptors(t_redir *redir)
{
	int		fd_in;
	int		fd_out;
	char	*temp;

	if (redir->output)
	{
		temp = (char *)redir->output->content;
		if (temp[0] == '1')
			fd_out = open(++temp, O_RDWR | O_CREAT | O_TRUNC, 0644);
		else
			fd_out = open(++temp, O_RDWR | O_CREAT | O_APPEND, 0666);
		dup2(fd_out, 1);
		close(fd_out);
	}
	if (redir->input)
	{
		fd_in = open(redir->input, O_RDONLY);
		dup2(fd_in, 0);
		close(fd_in);
	}
}

static void	error_of_redirect(t_redir *redir)
{
	int		fd_out;
	char	*out;

	if (redir->output)
	{
		out = redir->output->content;
		fd_out = open(++out, O_CREAT | O_TRUNC, S_IWRITE | S_IREAD);
		close (fd_out);
	}
	my_puterror(redir->input, NULL, ": No such file or directory");
}

void	work_with_redirect(t_redir *redir, t_matur *matur)
{
	int		fd_out;
	char	*out;
	int		pid;

	while (redir->output && redir->output->next)
	{
		out = redir->output->content;
		fd_out = open(++out, O_CREAT | O_TRUNC, S_IWRITE | S_IREAD);
		close (fd_out);
		redir->output = redir->output->next;
	}
	if (redir->error)
		error_of_redirect(redir);
	else
	{
		pid = fork();
		if (pid > 0)
			wait(NULL);
		else if (pid == 0)
		{
			matur->flag_pipe = 1;
			substitution_of_file_descriptors(redir);
			builtin_function_or_no(matur);
		}
	}
}
