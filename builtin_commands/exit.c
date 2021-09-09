#include "../mini.h"
static void	exit_with_argument(t_matur *matur)
{
	int	i;

	i = -1;
	while (matur->mass[1][++i] != '\0')
	{
		if (!my_isdigit(matur->mass[1][i]))
		{
			my_puterror("exit: ", matur->mass[1],
				": numeric argument required");
			exit (255);
		}
	}
	i = atoi(matur->mass[1]);
	exit (i);
}

void	my_exit(t_matur *matur)
{
	if (matur->mass[1] == NULL)
		exit (0);
	else if (matur->mass[2] == NULL)
		exit_with_argument(matur);
	else
	{
		my_puterror(matur->mass[0], NULL, ": too many arguments");
		matur->error = 1;
	}
}
