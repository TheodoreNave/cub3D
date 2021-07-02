/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:01:07 by tnave             #+#    #+#             */
/*   Updated: 2021/07/02 23:06:44 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	parsing_all_data(t_parse_list **parse, t_data *data)
{
	t_parse_list	*tmp;

	tmp = *parse;
	while (tmp)
	{
		data->parsing = ft_split_charset(tmp->content, " \t");
		if (parsing_textures_id(data))
			;
		else if (parsing_rgb_id(data))
			;
		else if (data->count && ft_one(tmp->content) && !data->mappy.index_map)
		{
			data->mappy.index_map = 1;
			parse_map(data, tmp);
			free_split(data->parsing);
			data->parsing = NULL;
			return (0);
		}
		else if (data->parsing[0])
			ft_error(2, "Invalid values\n", data);
		free_split(data->parsing);
		data->parsing = NULL;
		tmp = tmp->next;
	}
	return (0);
}

int	parsing_textures_id(t_data *data)
{
	if ((ft_strequ(data->parsing[0], "NO")
			|| ft_strequ(data->parsing[0], "SO")
			|| ft_strequ(data->parsing[0], "WE")
			|| ft_strequ(data->parsing[0], "EA")
			|| ft_strequ(data->parsing[0], "S")))
	{
		if (!(parse_textures(data->parsing, data)))
			error_parameters(data);
	}
	else
		return (0);
	data->count_params++;
	return (1);
}

int	parse_textures(char **tab, t_data *data)
{
	if (count_len_split(tab) != 2)
		ft_error(1, "Invalid Path\n", data);
	if (ft_strequ(tab[0], "NO"))
		data->no = ft_strdup(tab[1]);
	else if (ft_strequ(tab[0], "SO"))
		data->so = ft_strdup(tab[1]);
	else if (ft_strequ(tab[0], "WE"))
		data->we = ft_strdup(tab[1]);
	else if (ft_strequ(tab[0], "EA"))
		data->ea = ft_strdup(tab[1]);
	else if (ft_strequ(tab[0], "S"))
		data->s = ft_strdup(tab[1]);
	return (1);
}

int	parsing_rgb_id(t_data *data)
{
	if (ft_strequ(data->parsing[0], "F"))
	{
		if (!(parse_rgb(data->parsing, data, &data->floor)))
			ft_error(1, "Invalid RGB\n", data);
		data->count_params++;
	}
	else if (ft_strequ(data->parsing[0], "C"))
	{
		if (!(parse_rgb(data->parsing, data, &data->ceilling)))
			ft_error(1, "Invalid RGB\n", data);
		data->count_params++;
		if (data->count_params == 7)
			data->count = 1;
		else
			ft_error(1, "Invalid nb of sidenstifiers\n", data);
	}
	else
		return (0);
	return (1);
}

int	parse_rgb(char **tab, t_data *data, t_color *type)
{
	char	**virgule;

	if (!tab[1])
		return (0);
	if (count_char_in_string(tab[1], ',') != 2)
		ft_error(1, "Invalid nb of parameters\n", data);
	virgule = ft_split(tab[1], ',');
	if (count_len_split(virgule) != 3)
	{
		free_split(virgule);
		ft_error(1, "Invalid nb of parameters\n", data);
	}
	if (ft_digit_virgule(virgule, data))
	{
		type->t = 0;
		type->r = ft_atoi(virgule[0]);
		type->g = ft_atoi(virgule[1]);
		type->b = ft_atoi(virgule[2]);
	}
	if (type->r < RGB_MIN || type->r > RGB_MAX || type->g < RGB_MIN
		|| type->g > RGB_MAX || type->b < RGB_MIN || type->b > RGB_MAX)
		free_split(virgule);
	nice_type(data, type);
	free_split(virgule);
	return (1);
}
