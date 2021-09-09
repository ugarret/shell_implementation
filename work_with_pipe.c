#include "mini.h"

static void	pipe_function(t_matur *matur, int **buf_fd, int max, int i)
{
	if (i == 0)
	{
		close(buf_fd[i][0]);
		dup2(buf_fd[i][1], 1);
	}
	else if (i < max)
	{
		close(buf_fd[i - 1][1]);
		dup2(buf_fd[i - 1][0], 0);
		close(buf_fd[i][0]);
		dup2(buf_fd[i][1], 1);
	}
	else
	{
		close(buf_fd[i - 1][1]);
		dup2(buf_fd[i - 1][0], 0);
	}
	matur->flag_pipe = 1;
	builtin_function_or_no(matur);
}

static int	**create_arr_fd_and_pid(int count_pipe, int **buf_pid)
{
	int	**buf_fd;
	int	i;

	buf_fd = (int **)malloc(sizeof(int *) * count_pipe);
	if (!buf_fd)
		return (NULL);
	i = -1;
	while (++i < count_pipe)
	{
		buf_fd[i] = (int *)malloc(sizeof(int) * 2);
		pipe(buf_fd[i]);
	}
	*buf_pid = (int *)malloc(sizeof(int) * (count_pipe + 1));
	return (buf_fd);
}

void	work_with_pipe(int count_pipe, t_list **commands, t_matur *matur)
{
	int		*buf_pid;
	int		**buf_fd;
	t_list	*tmp;
	int		i;

	count_pipe--;
	buf_fd = create_arr_fd_and_pid(count_pipe, &buf_pid);
	tmp = *commands;
	i = 0;
	while (tmp != NULL)
	{
		matur->mass = tmp->content;
		buf_pid[i] = fork();
		if (buf_pid[i] > 0 && i != count_pipe)
			close(buf_fd[i][1]);
		else if (buf_pid[i] == 0)
		{
			pipe_function(matur, buf_fd, count_pipe, i);
			exit (0);
		}
		i++;
		tmp = tmp->next;
	}
	while (--i >= 0)
		waitpid(buf_pid[i], NULL, 0);
}
