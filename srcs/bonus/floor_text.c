/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:25:08 by tnave             #+#    #+#             */
/*   Updated: 2021/07/02 11:27:57 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	floor_init(t_data *data, int y)
{
	data->earth.ray_dirx_zero = data->ray->dir_x - data->ray->plane_x;
	data->earth.ray_diry_zero = data->ray->dir_y - data->ray->plane_y;
	data->earth.ray_dirx_one = data->ray->dir_x + data->ray->plane_x;
	data->earth.ray_diry_one = data->ray->dir_y + data->ray->plane_y;
	data->earth.row_distance = 0.5 * 720 / (y - 720 / 2);
	data->earth.floor_step_x = data->earth.row_distance
		* (data->earth.ray_dirx_one - data->earth.ray_dirx_zero) / 720;
	data->earth.floor_step_y = data->earth.row_distance
		* (data->earth.ray_diry_one - data->earth.ray_diry_zero) / 720;
	data->earth.floor_x = data->ray->pos_x + data->earth.row_distance
		* data->earth.ray_dirx_zero;
	data->earth.floor_y = data->ray->pos_y + data->earth.row_distance
		* data->earth.ray_diry_zero;
}

void	floor_text(int y, t_data *data, t_text *texture)
{
	t_text	tex;
	int		x;

	x = 0;
	tex = texture[6];
	floor_init(data, y);
	while (x < 720)
	{
		data->earth.cell_x = (int)(data->earth.floor_x);
		data->earth.cell_y = (int)(data->earth.floor_y);
		data->earth.tx = (int)(tex.width
				* (data->earth.floor_x - data->earth.cell_x)) & (tex.width - 1);
		data->earth.ty = (int)(tex.height * (data->earth.floor_y
					- data->earth.cell_y)) & (tex.height - 1);
		data->earth.floor_x += data->earth.floor_step_x;
		data->earth.floor_y += data->earth.floor_step_y;
		data->earth.i = data->earth.ty * tex.line_length
			+ data->earth.tx * (tex.bits_per_pixel / 8);
		if (y < data->ray->h && x < data->ray->w)
			my_mlx_pixel_put(data, x, y, create_trgb(0,
					(int)(unsigned char)tex.addr[data->earth.i + 2],
					(int)(unsigned char)tex.addr[data->earth.i + 1],
					(int)(unsigned char)tex.addr[data->earth.i]));
		x++;
	}
}
