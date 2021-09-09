#include "mini.h"

static int	live_life_execve(char *path, t_matur *matur)
{
	char	**env;
	int		status;
	pid_t	pid;

	if (!matur->flag_pipe)
		pid = fork();
	else
		pid = 0;
	if (pid < 0)
		exit(-1);
	else if (pid == 0)
	{
		env = list_to_arr(&matur->env);
		execve(path, matur->mass, env);
		exit(0);
	}
	else
	{
		wait(&status);
		matur->error = status / 256;
	}
	return (1);
}

static void	split_path_and_put_in_execve(t_matur *matur)
{
	struct stat	buf;
	char		**arr;
	int			i;
	int			res;
	int			flag;

	arr = my_split(search_element_in_list_on_key(&matur->env, "PATH"), ':');
	i = -1;
	flag = 0;
	while (arr[++i] != NULL)
	{
		arr[i] = my_strjoin_free_first_arg(my_strjoin_free_first_arg(arr[i], "/"), matur->mass[0]);
		res = stat(arr[i], &buf);
		if (res == 0 && (buf.st_mode & X_OK))
		{
			flag = live_life_execve(arr[i], matur);
			break ;
		}
	}
	free_arr(arr);
	if (!flag)
	{
		my_puterror(matur->mass[0], NULL, ": command not found");
		matur->error = 127;
	}
}

static void	work_with_execve(t_matur *matur)
{
	if (matur->mass[0][0] == '/' || matur->mass[0][0] == '.')
	{
		live_life_execve(matur->mass[0], matur);
		return ;
	}
	else if (!search_element_in_list_on_key(&matur->env, "PATH"))
	{
		my_puterror(matur->mass[0], NULL, ": No such file or directory");
		matur->error = 127;
		return ;
	}
	split_path_and_put_in_execve(matur);
}

void	builtin_function_or_no(t_matur *matur)
{
	if (!my_strncmp(matur->mass[0], "echo", 5))
		my_echo(matur);
	else if (!my_strncmp(matur->mass[0], "cd", 3))
		my_cd(matur);
	else if (!my_strncmp(matur->mass[0], "pwd", 4))
		my_pwd(matur);
	else if (!my_strncmp(matur->mass[0], "export", 7))
		my_export(matur);
	else if (!my_strncmp(matur->mass[0], "unset", 6))
		my_unset(matur);
	else if (!my_strncmp(matur->mass[0], "env", 4))
		my_env(matur);
	else if (!my_strncmp(matur->mass[0], "exit", 5))
		my_exit(matur);
	else
		work_with_execve(matur);
	if (matur->flag_pipe)
		exit(matur->error);
}
