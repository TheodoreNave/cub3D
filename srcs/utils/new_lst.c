/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:59:06 by tnave             #+#    #+#             */
/*   Updated: 2021/07/02 11:27:57 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_parse_list	*ft_lstnew(void *content)
{
	t_parse_list	*new_list;

	new_list = malloc(sizeof(t_parse_list));
	if (!(new_list))
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}

void	ft_lstadd_back(t_parse_list **alst, t_parse_list *new)
{
	t_parse_list	*end_list;

	while (!alst || !new)
		return ;
	if (*alst)
	{
		end_list = *alst;
		while (end_list->next != NULL)
			end_list = end_list->next;
		end_list->next = new;
	}
	else
		*alst = new;
}

int	ft_lstsize(t_parse_list *lst)
{
	int				i;
	t_parse_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
