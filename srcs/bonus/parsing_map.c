/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:22:31 by tnave             #+#    #+#             */
/*   Updated: 2021/07/02 11:27:57 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse_map(t_data *data, t_parse_list *tmp)
{
	data->mappy.map = (char **)malloc(sizeof(char *) * (ft_lstsize(tmp) + 1));
	if (!(data->mappy.map))
		return (0);
	map_check_error(data, tmp);
	data->mappy.map_height = data->mappy.nb_lignes;
	is_valid_map(data, data->ray);
	return (0);
}

int	is_valid_map(t_data *data, t_ray *ray)
{
	int			y;
	int			len;

	y = 0;
	len = data->mappy.nb_lignes;
	check_first_and_final_line(data->mappy.map[y], data);
	final_flash(data, ray);
	check_first_and_final_line(data->mappy.map[len - 1], data);
	return (1);
}

void	final_flash(t_data *data, t_ray *ray)
{
	int			y;
	int			x;

	y = 1;
	x = 0;
	if (!all_elements(data, ray))
		ft_error(1, "Not all elements in map\n", data);
	while (data->mappy.map[y])
	{
		check_one_first_char(data->mappy.map[y], data);
		while (data->mappy.map[y][x])
		{
			if (data->mappy.map[y][x] == '2')
				lstadd_back_slist(&data->sprites, lstnew_sprites(x, y));
			if (is_valid_char_in_map(data->mappy.map[y][x]))
				check_wall(data->mappy.map, x, y, data);
			x++;
		}
		x = 0;
		y++;
	}
}

int	all_elements(t_data *data, t_ray *ray)
{
	ray->all_y = 1;
	ray->all_x = 0;
	ray->all_pos = 0;
	while (data->mappy.map[ray->all_y])
	{
		while (data->mappy.map[ray->all_y][ray->all_x])
		{
			if (start_position(data->mappy.map[ray->all_y][ray->all_x]))
			{
				ray->pos_x = ray->all_y + 0.5;
				ray->pos_y = ray->all_x + 0.5;
				ray->start = data->mappy.map[ray->all_y][ray->all_x];
				let_def_position(ray);
				data->mappy.map[ray->all_y][ray->all_x] = '0';
				ray->all_pos++;
				if (ray->all_pos != 1)
					return (0);
			}
			ray->all_x++;
		}
		ray->all_y++;
		ray->all_x = 0;
	}
	return (ray->all_pos);
}

void	map_check_error(t_data *data, t_parse_list *tmp)
{
	int			i;

	i = 0;
	while (tmp)
	{
		data->tmpp = ft_strlen(tmp->content);
		if (data->mappy.map_width < data->tmpp)
			data->mappy.map_width = data->tmpp;
		data->mappy.map[i] = ft_strdup(tmp->content);
		data->mappy.nb_lignes++;
		if (!char_in_string(tmp->content, '1'))
		{
			if (data->mappy.map[i][0] == '\n' || data->mappy.map[i][0] == '\0')
				data->mappy.nl++;
		}
		else if (data->mappy.nl > 0)
		{
			data->mappy.map[i + 1] = NULL;
			ft_error(1, "Empty line in map\n", data);
		}
		i++;
		tmp = tmp->next;
	}
	data->mappy.map[i] = NULL;
}
