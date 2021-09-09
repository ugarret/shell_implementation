#include "../mini.h"

void	my_pwd(t_matur *matur)
{
	char	*dir;

	dir = getcwd(NULL, 0);
	my_putstr_fd(my_strjoin_free_first_arg(dir, "\n"), 1);
	matur->error = 0;
}
