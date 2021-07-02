/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:56:05 by tnave             #+#    #+#             */
/*   Updated: 2021/07/02 11:27:57 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	lstadd_back_slist(t_sprites **lst, t_sprites *new)
{
	t_sprites			*end_list;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		end_list = *lst;
		while (end_list->next != NULL)
			end_list = end_list->next;
		end_list->next = new;
	}
	else
		*lst = new;
}

int	ft_lstsize_slist(t_sprites *lst)
{
	int				i;
	t_sprites		*tmp;

	i = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_lstclear_parse(t_parse_list **lst, void (*del)(void *))
{
	t_parse_list	*end_list;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		end_list = *lst;
		del(end_list->content);
		*lst = end_list->next;
		free(end_list);
	}
	*lst = NULL;
}
