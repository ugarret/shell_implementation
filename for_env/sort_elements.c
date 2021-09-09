#include "../mini.h"

static void	swap(char **a, char **b)
{
	char	*t;

	t = *a;
	*a = *b;
	*b = t;
}

static t_list_env	*partition(t_list_env *head, t_list_env *end)
{
	t_list_env	*i;
	t_list_env	*j;

	i = head->previous;
	j = head;
	while (j != end)
	{
		if ((my_strncmp(j->key, end->key, my_strlen(j->key) + 1)) <= 0)
		{
			if (i == NULL)
				i = head;
			else
				i = i->next;
			swap(&(i->key), &(j->key));
			swap(&(i->value), &(j->value));
		}
		j = j->next;
	}
	if (i == NULL)
		i = head;
	else
		i = i->next;
	swap(&(i->key), &(j->key));
	swap(&(i->value), &(j->value));
	return (i);
}

static void	quick_sort(t_list_env *head, t_list_env *end)
{
	t_list_env	*center;

	if (end != NULL && head != end && head != end->next)
	{
		center = partition(head, end);
		quick_sort(head, center->previous);
		quick_sort(center->next, end);
	}
}

t_list_env	*sort_elements_of_list(t_list_env *list)
{
	t_list_env	*temp;

	temp = list;
	while (temp->next)
		temp = temp->next;
	quick_sort(list, temp);
	return (list);
}
