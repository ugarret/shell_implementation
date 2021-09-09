#include "../mini.h"

static int	error_of_validation(char *str, t_matur *matur)
{
	my_puterror("unset: `", str, "': not a valid identifier");
	matur->error = 1;
	return (0);
}

int	validation_of_arguments(char *str, t_matur *matur)
{
	int	i;

	i = 0;
	if (!str || (!(my_isalpha(str[i])) && str[i] != '_'))
		return (error_of_validation(str, matur));
	while (str[++i] != '\0' && str[i] != '=')
	{
		if (str[i] == '+')
		{
			if (str[i + 1] != '=')
				return (error_of_validation(str, matur));
			else
				break ;
		}
		else if (!(my_isalnum(str[i])) && str[i] != '_')
			return (error_of_validation(str, matur));
	}
	return (1);
}
