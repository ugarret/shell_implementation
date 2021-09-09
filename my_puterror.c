#include "mini.h"

void	my_puterror(char *command, char *argument, char *my_error)
{
	my_putstr_fd("bash: ", 2);
	if (command)
		my_putstr_fd(command, 2);
	if (argument)
		my_putstr_fd(argument, 2);
	if (my_error)
		my_putendl_fd(my_error, 2);
}
