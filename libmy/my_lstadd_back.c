#include "libmy.h"

void	my_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp_lst;

	if (!new)
		return ;
	if (lst && *lst)
	{
		temp_lst = *lst;
		while (temp_lst->next)
			temp_lst = temp_lst->next;
		temp_lst->next = new;
	}
	else
		*lst = new;
}
