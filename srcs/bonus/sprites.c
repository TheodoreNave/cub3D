/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:25:24 by tnave             #+#    #+#             */
/*   Updated: 2021/07/02 23:06:44 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	swap_tmp(t_sprites *tmp, t_sprites *tmp2)
{
	double	swap;

	swap = tmp2->x;
	tmp2->x = tmp->x;
	tmp->x = swap;
	swap = tmp2->y;
	tmp2->y = tmp->y;
	tmp->y = swap;
	swap = tmp2->distance;
	tmp2->distance = tmp->distance;
	tmp->distance = swap;
}

void	sorting_sprites(t_sprites **lst)
{
	t_sprites	*tmp;
	t_sprites	*tmp2;

	tmp = *lst;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp2->distance > tmp->distance)
				swap_tmp(tmp, tmp2);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	init_sp_two(t_data *data)
{
	if (data->utils.draw_end_y >= 720)
		data->utils.draw_end_y = 720 - 1;
	data->utils.sprite_width = abs((int)(720 / (data->utils.transform_y)))
		/ 1.5;
	data->utils.draw_start_x = -data->utils.sprite_width
		/ 2 + data->utils.sprite_screen_x;
	if (data->utils.draw_start_x < 0)
		data->utils.draw_start_x = 0;
	data->utils.draw_end_x = data->utils.sprite_width
		/ 2 + data->utils.sprite_screen_x;
	if (data->utils.draw_end_x >= 720)
		data->utils.draw_end_x = 720 - 1;
	data->utils.stripe = data->utils.draw_start_x;
}

void	init_sp(t_data *data, t_sprites *tmp)
{
	data->utils.sprite_x = tmp->y - data->ray->pos_x + 0.5;
	data->utils.sprite_y = tmp->x - data->ray->pos_y + 0.5;
	data->utils.inv_det = 1.0 / (data->ray->plane_x * data->ray->dir_y
			- data->ray->dir_x * data->ray->plane_y);
	data->utils.transform_x = data->utils.inv_det
		* (data->ray->dir_y * data->utils.sprite_x - data->ray->dir_x
			* data->utils.sprite_y);
	data->utils.transform_y = data->utils.inv_det * (-data->ray->plane_y
			* data->utils.sprite_x + data->ray->plane_x * data->utils.sprite_y);
	data->utils.sprite_screen_x = (int)((720 / 2) * (1 + data->utils.transform_x
				/ data->utils.transform_y));
	data->utils.v_move_screen = (int)(200.0 / data->utils.transform_y);
	data->utils.sprite_height = abs((int)(720
				/ (data->utils.transform_y))) / 1.5;
	data->utils.draw_start_y = -data->utils.sprite_height / 2 + 720 / 2
		+ data->utils.v_move_screen;
	if (data->utils.draw_start_y < 0)
		data->utils.draw_start_y = 0;
	data->utils.draw_end_y = data->utils.sprite_height / 2 + 720
		/ 2 + data->utils.v_move_screen;
	init_sp_two(data);
}

void	ft_sprite(t_data *data, t_text *texture)
{
	int			i;
	t_sprites	*tmp;

	i = 0;
	tmp = data->sprites;
	if (!data->sprites)
		return ;
	while (tmp)
	{
		tmp->order = i;
		tmp->distance = ((data->ray->pos_x - tmp->y)
				* (data->ray->pos_x - tmp->y) + (data->ray->pos_y - tmp->x)
				* (data->ray->pos_y - tmp->x));
		i++;
		tmp = tmp->next;
	}
	sorting_sprites(&data->sprites);
	print_sprites(data, texture, tmp);
}
