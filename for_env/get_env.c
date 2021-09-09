#include "../mini.h"

void	get_env(char **env, t_matur *matur)
{
	int		count;
	int		len;
	char	*key;
	char	*val;

	count = 0;
	while (env[count] != NULL)
	{
		len = 0;
		while (env[count][len] != '=' && env[count][len] != '\0')
			len++;
		key = my_substr(env[count], 0, len);
		if (env[count][len] == '=')
		{
			len++;
			val = my_substr(env[count], len, my_strlen(&env[count][len]));
		}
		else
			val = NULL;
		add_element(&matur->env, new_element(key, val));
		count++;
	}
}
