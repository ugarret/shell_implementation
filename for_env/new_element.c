/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugarret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 05:56:04 by ugarret           #+#    #+#             */
/*   Updated: 2021/03/09 05:56:07 by ugarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini.h"

t_list_env	*new_element(char *key, char *value)
{
	t_list_env	*lst;

	lst = (t_list_env *)malloc(sizeof(t_list_env));
	if (!lst)
		return (NULL);
	lst->key = key;
	lst->value = value;
	lst->next = NULL;
	lst->previous = NULL;
	return (lst);
}
