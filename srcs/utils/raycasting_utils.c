/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:21:25 by tnave             #+#    #+#             */
/*   Updated: 2021/07/02 11:27:57 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ray_init(t_data *data)
{
	t_sprites	*tmp;

	tmp = data->sprites;
	data->ray->w = 720;
	data->ray->h = 720;
	data->ray->movespeed = 0.1;
	data->ray->rotspeed = 0.1;
	while (tmp)
	{
		tmp->zbuffer = (double *)malloc(sizeof(double) * data->ray->h);
		if (!(tmp->zbuffer))
			ft_error(0, "Error malloc\n", data);
		tmp = tmp->next;
	}
}

void	ft_verline(int x, t_data *data, t_text *texture)
{
	if (data->ray->draw_start < data->ray->draw_end)
	{
		choose_ray(data, texture);
		draw_text(data, texture, x, data->ray->draw_start);
		data->ray->draw_start++;
	}
}
