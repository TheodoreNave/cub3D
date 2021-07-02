/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:42:50 by tnave             #+#    #+#             */
/*   Updated: 2021/07/02 11:27:57 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	char_in_string(char *str, char c)
{
	int				i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	check_first_and_final_line(char *line, t_data *data)
{
	int				i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			ft_error(1, "Map not closed\n", data);
		i++;
	}
}

void	check_one_first_char(char *line, t_data *data)
{
	int				i;

	i = 0;
	if (line[i] != '1' && line[i] != ' ' && line[i] != '\n' && line[i] != '\0')
		ft_error(0, "Invalid map\n", data);
	while (is_valid_char(line[i]))
		i++;
	while (line[i] && (line[i] == ' ' || line[i] == '\0' || line[i] == '\t'))
		i--;
	if (line[i] != '1' && line[i] != '\0' && ft_strlen(line) > 1)
		ft_error(0, "Invalid map\n", data);
}

void	check_wall(char **map, int x, int y, t_data *data)
{
	if (map[y - 1][x - 1] == '\0' || map[y - 1][x - 1] == ' ')
		ft_error(0, "Invalid map\n", data);
	else if (map[y - 1][x] == '\0' || map[y - 1][x] == ' ' )
		ft_error(0, "Invalid map\n", data);
	else if (map[y - 1][x + 1] == '\0' || map[y - 1][x + 1] == ' ')
		ft_error(0, "Invalid map\n", data);
	else if (map[y][x - 1] == '\0' || map[y][x - 1] == ' ')
		ft_error(0, "Invalid map\n", data);
	else if (!map[y + 1] || map[y + 1][x - 1] == '\0'
	|| map[y + 1][x - 1] == ' ')
		ft_error(0, "Invalid map\n", data);
	else if (!map[y + 1] || map[y + 1][x] == '\0' || map[y + 1][x] == ' ')
		ft_error(0, "Invalid map\n", data);
	else if (!map[y + 1] || map[y + 1][x + 1] == '\0'
	|| map[y + 1][x + 1] == ' ')
		ft_error(0, "Invalid map\n", data);
}

int	str_is_digit(char *str)
{
	int				i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
