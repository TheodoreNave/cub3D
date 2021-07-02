/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:25:14 by tnave             #+#    #+#             */
/*   Updated: 2021/07/02 23:06:44 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	drawSquare(t_data *data, int x, int y)
{
	int	x2;
	int	y2;
	int	x_end;
	int	y_end;

	x2 = x;
	y2 = y;
	x_end = x + data->mappy.map_size - 1;
	y_end = y + data->mappy.map_size - 1;
	while (y2 < y_end && y2 < 720)
	{
		x2 = x;
		while (x2 < x_end && x2 < 720)
		{
			my_mlx_pixel_put(data, x2, y2, 0x0FFFFFF);
			x2++;
		}
		y2++;
	}
}

void	drawSquareblack(t_data *data, int x, int y)
{
	int	x2;
	int	y2;
	int	x_end;
	int	y_end;

	x2 = x;
	y2 = y;
	x_end = x + data->mappy.map_size - 1;
	y_end = y + data->mappy.map_size - 1;
	while (y2 < y_end)
	{
		x2 = x;
		while (x2 < x_end)
		{
			my_mlx_pixel_put(data, x2, y2, 0x0000000);
			x2++;
		}
		y2++;
	}
}

void	drawMap2D(t_data *data)
{
	int	x;
	int	y;
	int	xo;
	int	yo;

	x = 0;
	y = 0;
	while (data->mappy.map[y])
	{
		while (data->mappy.map[y][x])
		{
			xo = x * data->mappy.map_size;
			yo = y * data->mappy.map_size;
			if (data->mappy.map[y][x] == '1')
				drawSquare(data, xo, yo);
			else
				drawSquareblack(data, xo, yo);
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_player(t_ray *ray, t_data *data)
{
	int	x;
	int	y;
	int	x2;
	int	y2;

	x = (int)ray->pos_y * data->mappy.map_size;
	y = (int)ray->pos_x * data->mappy.map_size;
	x2 = x;
	y2 = y;
	data->mappy.x_end = x + data->mappy.map_size;
	data->mappy.y_end = y + data->mappy.map_size;
	while (y2 < data->mappy.y_end)
	{
		x2 = x;
		while (x2 < data->mappy.x_end)
		{
			my_mlx_pixel_put(data, x2, y2, 0xFFFF00);
			x2++;
		}
		y2++;
	}
}

void	draw_line(t_ray *ray, t_data *data, int x, int y)
{
	int	x2;
	int	y2;
	int	x_end;
	int	y_end;

	(void)ray;
	x2 = x;
	y2 = y;
	x_end = x + ray->pdx * 10;
	y_end = y + ray->pdy * 10;
	while (y2 < y_end)
	{
		x2 = x;
		while (x2 < x_end)
		{
			my_mlx_pixel_put(data, x2, y2, 0x8B0000);
			x2++;
		}
		y2++;
	}
}
