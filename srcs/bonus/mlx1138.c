/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx1138.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:03:14 by tnave             #+#    #+#             */
/*   Updated: 2021/07/02 23:06:44 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_screen(t_data *data)
{
	int		x;
	int		y;
	int		floor;
	int		ceiling;

	x = 0;
	y = 0;
	floor = my_create_trgb(data->floor);
	ceiling = my_create_trgb(data->ceilling);
	while (y < 720)
	{
		x = 0;
		while (x < 720)
		{
			my_mlx_pixel_put(data, x, y, floor);
			if (y <= 720 / 2)
				my_mlx_pixel_put(data, x, y, ceiling);
			x++;
		}
		y++;
	}
}

void	handle_movements(t_data *data)
{
	if (data->keys.right)
		key_hook_right(data);
	if (data->keys.left)
		key_hook_left(data);
	if (data->keys.back)
		key_hook_backward(data);
	if (data->keys.forward)
		key_hook_forward(data);
	if (data->keys.rotate_left)
		key_hook_rotate_left(data);
	if (data->keys.rotate_right)
		key_hook_rotate_right(data);
}

int	ft_refresh(t_data *data, t_text *texture)
{
	texture = data->texture;
	handle_movements(data);
	if (data->refresh == 1)
	{
		ft_screen(data);
		raycasting(data, texture);
		if (data->map_key && data->mappy.nb_lignes < 20)
			mini_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	data->refresh = 0;
	return (0);
}

void	mlx_1138(t_data *data, t_text *texture)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 720, 720, "Cub3D");
	data->img.img = mlx_new_image(data->mlx, 720, 720);
	data->img.addr = mlx_get_data_addr(data->img.img,
			&data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian);
	ray_init(data);
	data->refresh = 1;
	data->mappy.map_size = 5;
	ft_texture(data, texture);
	add_texture(texture);
	mlx_hook(data->win, 9, 1L << 21, ft_refresh, data);
	mlx_hook(data->win, 33, 1L << 17, exit_function, data);
	mlx_hook(data->win, 2, 1L << 0, key_hook, data);
	mlx_loop_hook(data->mlx, ft_refresh, data);
	mlx_hook(data->win, 3, 1L << 1, key_hook_end, data);
	mlx_loop(data->mlx);
}
