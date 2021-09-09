#include "../mini.h"

char	*search_element_in_list_on_key(t_list_env **list, char *key)
{
	t_list_env	*tmp;
	int			len;

	if (!list || !key)
		return (NULL);
	len = my_strlen(key);
	tmp = *list;
	while (tmp != NULL)
	{
		if (!my_strncmp(tmp->key, key, len + 1))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
