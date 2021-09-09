#include "../mini.h"

static void	print_word(char *argumen, char *next_argument, int fd)
{
	write(fd, argumen, my_strlen(argumen));
	if (next_argument != NULL)
		write(1, " ", 1);
}

void	my_echo(t_matur *matur)
{
	int	flag;
	int	i;
	int	j;

	flag = 0;
	i = 0;
	while (!my_strncmp(matur->mass[++i], "-n", 2))
	{
		j = 1;
		while (matur->mass[i][j] == 'n')
			j++;
		if (matur->mass[i][j] == '\0')
			flag = 1;
		else
			break ;
	}
	while (matur->mass[i] != NULL)
	{
		print_word(matur->mass[i], matur->mass[i + 1], 1);
		i++;
	}
	if (!flag)
		write(1, "\n", 1);
	matur->error = 0;
}
