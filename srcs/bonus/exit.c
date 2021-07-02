/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:08:30 by tnave             #+#    #+#             */
/*   Updated: 2021/07/02 11:27:57 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	exit_function(t_data *data)
{
	if (data->mappy.map)
		free_split(data->mappy.map);
	if (data->parsing)
		free_split(data->parsing);
	free_all_tabs(data);
	ft_lstclear_sprites(&data->sprites, free);
	if (data->mlx && data->win)
	{
		ft_clear_image(data);
		mlx_destroy_display(data->mlx);
	}
	free(data->mlx);
	if (data->parse)
		ft_lstclear_parse(&data->parse, free);
	exit(0);
	return (0);
}

void	ft_clear_image(t_data *data)
{
	if (data->mlx)
		mlx_destroy_image(data->mlx, data->img.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->texture[0].img)
		mlx_destroy_image(data->mlx, data->texture[0].img);
	if (data->texture[1].img)
		mlx_destroy_image(data->mlx, data->texture[1].img);
	if (data->texture[2].img)
		mlx_destroy_image(data->mlx, data->texture[2].img);
	if (data->texture[3].img)
		mlx_destroy_image(data->mlx, data->texture[3].img);
	if (data->texture[4].img)
		mlx_destroy_image(data->mlx, data->texture[4].img);
	if (data->texture[5].img)
		mlx_destroy_image(data->mlx, data->texture[5].img);
	if (data->texture[6].img)
		mlx_destroy_image(data->mlx, data->texture[6].img);
}
