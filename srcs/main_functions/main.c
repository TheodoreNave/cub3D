/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:04:11 by tnave             #+#    #+#             */
/*   Updated: 2021/07/02 23:06:44 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	parse_file(char *str, t_data *data)
{
	data->fd = open(str, O_DIRECTORY);
	if (data->fd > 0)
	{
		close(data->fd);
		ft_error(3, "Badd it's a Directory", data);
	}
	data->fd = open(str, O_RDONLY);
	if (data->fd < 0)
		ft_error(3, "Invalid file", data);
	return (data->fd);
}

int	valid_file(char *str, t_data *data)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		ft_error(3, "Invalid file", data);
	if (str[len - 4] == '.' && str[len - 3] == 'c'
		&& str[len - 2] == 'u' && str[len - 1] == 'b')
		return (parse_file(str, data));
	else
		ft_error(3, "Wrong extension", data);
	return (0);
}

int	main(int argc, char **argv)
{
	char		*line;
	t_data		data;
	t_ray		ray;
	t_text		texture[7];

	ft_memset(&data, 0, sizeof(t_data));
	ft_memset(&texture, 0, sizeof(t_text) * 8);
	ft_memset(&data.mappy, 0, sizeof(t_mappy));
	ft_memset(&ray, 0, sizeof(t_ray));
	line = NULL;
	data.texture = texture;
	data.ray = &ray;
	if (argc != 2)
		ft_error(3, "Wrong argument", &data);
	data.fd = valid_file(argv[1], &data);
	parse_file(argv[1], &data);
	while (get_next_line(data.fd, &line))
		ft_lstadd_back(&data.parse, ft_lstnew(line));
	ft_lstadd_back(&data.parse, ft_lstnew(line));
	parsing_all_data(&data.parse, &data);
	if (!data.mappy.index_map)
		ft_error(2, "Invalid Map\n", &data);
	close(data.fd);
	mlx_1138(&data, data.texture);
	return (0);
}
