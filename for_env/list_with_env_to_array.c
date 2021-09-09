#include "../mini.h"

char	**list_to_arr(t_list_env **list)
{
	t_list_env	*tmp;
	char		**array;
	char		*str;
	int			count;

	count = 0;
	tmp = *list;
	while (tmp->next)
	{
		tmp = tmp->next;
		count++;
	}
	array = (char **)malloc(sizeof(char *) * (count + 1));
	if (!array)
		return (NULL);
	tmp = *list;
	array[count] = NULL;
	while (--count >= 0)
	{
		str = my_strjoin(tmp->key, "=");
		array[count] = my_strjoin(str, tmp->value);
		tmp = tmp->next;
		free(str);
	}
	return (array);
}
