#include "../mini.h"

void	my_env(t_matur *matur)
{
	t_list_env	*tmp;

	tmp = matur->env;
	if (!(search_element_in_list_on_key(&matur->env, "PATH")))
	{
		my_puterror(matur->mass[0], NULL, ": No such file or directory");
		matur->error = 127;
	}
	else
	{
		while (tmp != NULL)
		{
			if (tmp->value != NULL)
			{
				my_putstr_fd(tmp->key, 1);
				write(1, "=", 1);
				my_putstr_fd(tmp->value, 1);
				write(1, "\n", 1);
			}
			tmp = tmp->next;
		}
		matur->error = 0;
	}
}
