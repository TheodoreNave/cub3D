/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:25:20 by tnave             #+#    #+#             */
/*   Updated: 2021/07/02 23:06:44 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	sky_init(t_data *data, int y)
{
	data->sky.ray_dirx_zero = data->ray->dir_x - data->ray->plane_x;
	data->sky.ray_diry_zero = data->ray->dir_y - data->ray->plane_y;
	data->sky.ray_dirx_one = data->ray->dir_x + data->ray->plane_x;
	data->sky.ray_diry_one = data->ray->dir_y + data->ray->plane_y;
	data->sky.row_distance = 0.5 * 720 / (y - 720 / 2);
	data->sky.floor_step_x = data->sky.row_distance
		* (data->sky.ray_dirx_one - data->sky.ray_dirx_zero) / 720;
	data->sky.floor_step_y = data->sky.row_distance
		* (data->sky.ray_diry_one - data->sky.ray_diry_zero) / 720;
	data->sky.floor_x = data->ray->pos_x + data->sky.row_distance
		* data->sky.ray_dirx_zero;
	data->sky.floor_y = data->ray->pos_y + data->sky.row_distance
		* data->sky.ray_diry_zero;
}

void	sky_text(int y, t_data *data, t_text *texture)
{
	t_text	tex;
	int		x;

	x = 0;
	tex = texture[5];
	sky_init(data, y);
	while (x < 720)
	{
		data->sky.cell_x = (int)(data->sky.floor_x);
		data->sky.cell_y = (int)(data->sky.floor_y);
		data->sky.tx = (int)(tex.width
				* (data->sky.floor_x - data->sky.cell_x)) & (tex.width - 1);
		data->sky.ty = (int)(tex.height
				* (data->sky.floor_y - data->sky.cell_y)) & (tex.height - 1);
		data->sky.floor_x += data->sky.floor_step_x;
		data->sky.floor_y += data->sky.floor_step_y;
		data->sky.i = data->sky.ty * tex.line_length
			+ data->sky.tx * (tex.bits_per_pixel / 8);
		if (y < data->ray->h && x < data->ray->w)
			my_mlx_pixel_put(data, x, y, create_trgb(0,
					(int)(unsigned char)tex.addr[data->sky.i + 2],
					(int)(unsigned char)tex.addr[data->sky.i + 1],
					(int)(unsigned char)tex.addr[data->sky.i]));
		x++;
	}
}
