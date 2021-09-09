#include "../mini.h"

char	*strjoin_free(char *str1, char *str2)
{
	char	*p;

	if (!str1)
		return (str2);
	if (!str2)
		return (str1);
	p = my_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (p);
}

void	add_to_lst(t_lstc *lstc, void *p)
{
	my_lstadd_back(&lstc->lst, my_lstnew(p));
	lstc->count++;
}

void	clear_lst(t_lstc *lstc)
{
	my_lstclear(&lstc->lst, free);
	lstc->count = 0;
}

void	lst_free(t_lstc *lstc)
{
	t_list	*tmp;

	tmp = lstc->lst;
	while (tmp)
	{
		tmp = tmp->next;
		free(lstc->lst);
		lstc->lst = tmp;
	}
	lstc->lst = NULL;
	lstc->count = 0;
}

void	allocate_mem(t_matur *matur, t_lstc *collector)
{
	int		j;
	t_list	*temp;

	temp = collector->lst;
	matur->mass = malloc(sizeof(char *) * (collector->count + 1));
	matur->mass[collector->count] = NULL;
	j = 0;
	while (j < collector->count)
	{
		matur->mass[j++] = temp->content;
		temp = temp->next;
	}
}
