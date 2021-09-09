#include "../mini.h"

int	replace_value(t_list_env **list, char *key, char *new)
{
	t_list_env	*tmp;
	int			len;

	if (!list || !key)
		return (0);
	len = my_strlen(key);
	tmp = *list;
	while (tmp != NULL)
	{
		if (!my_strncmp(tmp->key, key, len + 1))
		{
			free(tmp->value);
			tmp->value = new;
		}
		tmp = tmp->next;
	}
	return (1);
}
