#include "../mini.h"

void	my_unset(t_matur *matur)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (matur->mass[++i] != NULL)
	{
		if (validation_of_arguments(matur->mass[i], matur))
			delete_element_from_list(&matur->env, matur->mass[i]);
		else
			flag = 1;
	}
	if (!flag)
		matur->error = 0;
}
