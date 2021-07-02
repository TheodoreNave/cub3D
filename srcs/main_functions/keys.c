/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:43:18 by tnave             #+#    #+#             */
/*   Updated: 2021/07/02 23:06:44 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	key_hook_rotate_right(t_data *data)
{
	data->refresh = 1;
	data->keys.rotate_right = 1;
	if (data->keys.rotate_right == 1)
	{
		data->ray->old_dir_x = data->ray->dir_x;
		data->ray->dir_x = data->ray->dir_x * cos(-data->ray->rotspeed)
			- data->ray->dir_y * sin(-data->ray->rotspeed);
		data->ray->dir_y = data->ray->old_dir_x * sin(-data->ray->rotspeed)
			+ data->ray->dir_y * cos(-data->ray->rotspeed);
		data->ray->old_plane_x = data->ray->plane_x;
		data->ray->plane_x = data->ray->plane_x * cos(-data->ray->rotspeed)
			- data->ray->plane_y * sin(-data->ray->rotspeed);
		data->ray->plane_y = data->ray->old_plane_x * sin(-data->ray->rotspeed)
			+ data->ray->plane_y * cos(-data->ray->rotspeed);
	}
	return (1);
}

int	key_hook_rotate_left(t_data *data)
{
	data->refresh = 1;
	data->keys.rotate_left = 1;
	if (data->keys.rotate_left == 1)
	{
		data->ray->old_dir_x = data->ray->dir_x;
		data->ray->dir_x = data->ray->dir_x * cos(data->ray->rotspeed)
			- data->ray->dir_y * sin(data->ray->rotspeed);
		data->ray->dir_y = data->ray->old_dir_x * sin(data->ray->rotspeed)
			+ data->ray->dir_y * cos(data->ray->rotspeed);
		data->ray->old_plane_x = data->ray->plane_x;
		data->ray->plane_x = data->ray->plane_x * cos(data->ray->rotspeed)
			- data->ray->plane_y * sin(data->ray->rotspeed);
		data->ray->plane_y = data->ray->old_plane_x * sin(data->ray->rotspeed)
			+ data->ray->plane_y * cos(data->ray->rotspeed);
	}
	return (1);
}

int	key_hook_backward(t_data *data)
{
	data->refresh = 1;
	data->keys.back = 1;
	if (data->keys.back == 1)
	{
		if (data->mappy.map[(int)(data->ray->pos_x - data->ray->dir_x
				* data->ray->movespeed)][(int)(data->ray->pos_y)] == '0')
			data->ray->pos_x -= data->ray->dir_x * data->ray->movespeed;
		if (data->mappy.map[(int)(data->ray->pos_x)][(int)(data->ray->pos_y
				- data->ray->dir_y * data->ray->movespeed)] == '0')
			data->ray->pos_y -= data->ray->dir_y * data->ray->movespeed;
	}
	return (1);
}

int	key_hook_forward(t_data *data)
{
	data->refresh = 1;
	data->keys.forward = 1;
	if (data->keys.forward == 1)
	{
		if (data->mappy.map[(int)(data->ray->pos_x + data->ray->dir_x
				* data->ray->movespeed)][(int)(data->ray->pos_y)] == '0')
			data->ray->pos_x += data->ray->dir_x * data->ray->movespeed;
		if (data->mappy.map[(int)(data->ray->pos_x)][(int)(data->ray->pos_y
			+ data->ray->dir_y * data->ray->movespeed)] == '0')
			data->ray->pos_y += data->ray->dir_y * data->ray->movespeed;
	}
	return (1);
}
