/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:56:05 by tnave             #+#    #+#             */
/*   Updated: 2021/07/02 23:06:44 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_sprites	*lstnew_sprites(int x, int y)
{
	t_sprites			*new_list;

	new_list = malloc(sizeof(t_sprites));
	if (!(new_list))
		return (NULL);
	ft_memset(new_list, 0, sizeof(t_sprites));
	new_list->x = x;
	new_list->y = y;
	new_list->next = NULL;
	return (new_list);
}

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

void	ft_lstclear_sprites(t_sprites **lst, void (*del)(void *))
{
	t_sprites		*tmp;
	t_sprites		*tpmp;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		tpmp = tmp->next;
		free(tmp->zbuffer);
		free(tmp);
		tmp = tpmp;
	}
	lst = NULL;
}
