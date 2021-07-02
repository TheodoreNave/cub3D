/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:51:08 by tnave             #+#    #+#             */
/*   Updated: 2021/07/02 11:27:57 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid_char_in_map(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E'
		|| c == '0');
}

int	start_position(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

int	is_valid_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E'
		|| c == '0' || c == '1' || c == ' ');
}

void	let_def_position(t_ray *ray)
{
	if (ray->start == 'N')
		ray->dir_x = -1;
	if (ray->start == 'S')
		ray->dir_x = 1;
	if (ray->start == 'W')
		ray->dir_y = -1;
	if (ray->start == 'E')
		ray->dir_y = 1;
	if (ray->start == 'N')
		ray->plane_y = 0.66;
	if (ray->start == 'S')
		ray->plane_y = -0.66;
	if (ray->start == 'W')
		ray->plane_x = -0.66;
	if (ray->start == 'E')
		ray->plane_x = 0.66;
}

void	nice_type(t_data *data, t_color *type)
{
	if (type->r < RGB_MIN || type->r > RGB_MAX)
		ft_error(1, "Max/min value reached\n", data);
	if (type->g < RGB_MIN || type->g > RGB_MAX)
		ft_error(1, "Max/min value reached\n", data);
	if (type->b < RGB_MIN || type->b > RGB_MAX)
		ft_error(1, "Max/min value reached\n", data);
}
