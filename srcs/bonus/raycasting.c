/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:17:46 by tnave             #+#    #+#             */
/*   Updated: 2021/07/02 23:06:44 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	raycasting(t_data *data, t_text *texture)
{
	int			x;
	t_sprites	*tmp;

	x = 0;
	ft_text_sky_floor(data, texture);
	while (x < data->ray->w)
	{
		data->ray->camera_x = 2.0 * x / (double)data->ray->w - 1.0;
		raycasting_one(data, data->ray);
		raycasting_two(data->ray);
		dda_calcul(data->ray, data);
		raycasting_last(data->ray);
		ft_verline(x, data, texture);
		tmp = data->sprites;
		while (tmp)
		{
			tmp->zbuffer[x] = data->ray->perp_wall_dist;
			tmp = tmp->next;
		}
		x++;
	}
	ft_sprite(data, texture);
}

void	raycasting_one(t_data *data, t_ray *ray)
{
	(void)data;
	ray->rdx = ray->dir_x + ray->plane_x * ray->camera_x;
	ray->rdy = ray->dir_y + ray->plane_y * ray->camera_x;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	ray->side_dist_x = 0;
	ray->side_dist_y = 0;
	ray->delta_dist_x = fabs(1 / ray->rdx);
	ray->delta_dist_y = fabs(1 / ray->rdy);
	ray->perp_wall_dist = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->hit = 0;
	ray->side = 0;
}

void	raycasting_two(t_ray *ray)
{
	if (ray->rdx < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->delta_dist_x;
	}
	if (ray->rdy < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->delta_dist_y;
	}
}

void	dda_calcul(t_ray *ray, t_data *data)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->mappy.map[ray->map_x][ray->map_y] == '1')
			ray->hit = 1;
	}
}

void	raycasting_last(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - ray->pos_x + (1 - ray->step_x) / 2)
			/ ray->rdx;
	else
		ray->perp_wall_dist = (ray->map_y - ray->pos_y + (1 - ray->step_y) / 2)
			/ ray->rdy;
	ray->line_height = (int)(ray->h / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + ray->h / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + ray->h / 2;
	if (ray->draw_end >= ray->h)
		ray->draw_end = ray->h - 1;
}
