/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 03:50:50 by ugarret           #+#    #+#             */
/*   Updated: 2021/03/09 03:50:58 by ugarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

static void	free_element(t_list_env	*tmp)
{
	free(tmp->key);
	free(tmp->value);
	free(tmp);
}

int	delete_element_from_list(t_list_env **list, char *key)
{
	t_list_env	*tmp;
	t_list_env	*prev;
	t_list_env	*next;
	int			len;

	if (!list || !key)
		return (1);
	len = my_strlen(key);
	tmp = *list;
	while (tmp != NULL)
	{
		prev = tmp->previous;
		next = tmp->next;
		if (!my_strncmp(tmp->key, key, len + 1))
		{
			if (prev)
				prev->next = tmp->next;
			if (next)
				next->previous = tmp->previous;
			free_element (tmp);
			return (0);
		}
		tmp = tmp->next;
	}
	return (0);
}
