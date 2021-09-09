#include "libmy.h"

void	my_lstclear(t_list **lst, void (*del_f)(void *))
{
	t_list	*temp_lst;
	t_list	*to_del_node;

	if ((!lst && !(*lst) && !del_f) || !lst || !(*lst) || !del_f)
		return ;
	temp_lst = *lst;
	while (temp_lst)
	{
		if (temp_lst->content)
			del_f(temp_lst->content);
		to_del_node = temp_lst;
		temp_lst = temp_lst->next;
		free(to_del_node);
	}
	*lst = NULL;
}
