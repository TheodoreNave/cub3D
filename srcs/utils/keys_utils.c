/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:17:59 by tnave             #+#    #+#             */
/*   Updated: 2021/07/02 23:06:44 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == LEFT_A)
		data->keys.left = 1;
	if (keycode == RIGHT_D)
		data->keys.right = 1;
	if (keycode == FORWARD_W)
		data->keys.forward = 1;
	if (keycode == BACK_S)
		data->keys.back = 1;
	if (keycode == ROTATE_LEFT)
		data->keys.rotate_left = 1;
	if (keycode == ROTATE_RIGHT)
		data->keys.rotate_right = 1;
	if (keycode == ESC)
		exit_function(data);
	return (1);
}

int	key_hook_left(t_data *data)
{
	data->refresh = 1;
	data->keys.left = 1;
	if (data->keys.left == 1)
	{
		if (data->mappy.map[(int)(data->ray->pos_x - data->ray->plane_x
				* data->ray->movespeed)][(int)(data->ray->pos_y)] == '0')
			data->ray->pos_x -= data->ray->plane_x * data->ray->movespeed;
		if (data->mappy.map[(int)(data->ray->pos_x)]
			[(int)(data->ray->pos_y - data->ray->plane_y
				* data->ray->movespeed)] == '0')
			data->ray->pos_y -= data->ray->plane_y * data->ray->movespeed;
	}
	return (1);
}

int	key_hook_right(t_data *data)
{
	data->refresh = 1;
	data->keys.right = 1;
	if (data->keys.right == 1)
	{
		if (data->mappy.map[(int)(data->ray->pos_x + data->ray->plane_x
				* data->ray->movespeed)][(int)(data->ray->pos_y)] == '0')
			data->ray->pos_x += data->ray->plane_x * data->ray->movespeed;
		if (data->mappy.map[(int)(data->ray->pos_x)]
			[(int)(data->ray->pos_y + data->ray->plane_y
			* data->ray->movespeed)] == '0')
			data->ray->pos_y += data->ray->plane_y * data->ray->movespeed;
	}
	return (1);
}

int	key_hook_end(int keycode, t_data *data)
{
	if (keycode == FORWARD_W)
		data->keys.forward = 0;
	if (keycode == BACK_S)
		data->keys.back = 0;
	if (keycode == LEFT_A)
		data->keys.left = 0;
	if (keycode == RIGHT_D)
		data->keys.right = 0;
	if (keycode == ROTATE_LEFT)
		data->keys.rotate_left = 0;
	if (keycode == ROTATE_RIGHT)
		data->keys.rotate_right = 0;
	return (1);
}
