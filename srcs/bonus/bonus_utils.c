/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 05:40:44 by tnave             #+#    #+#             */
/*   Updated: 2021/07/02 11:27:57 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	mini_map(t_data *data)
{
	drawMap2D(data);
	draw_player(data->ray, data);
}

void	ft_text_sky_floor(t_data *data, t_text *texture)
{
	int	y;

	y = 0;
	while (y < 720)
	{
		y++;
		sky_text(y, data, texture);
		if (y <= 720 / 2 + 1)
			floor_text(y, data, texture);
	}
}

void	pixel_put_sp(t_data *data, t_text *texture, int y)
{
	t_text	tex;

	tex = texture[4];
	data->utils.d = (y - data->utils.v_move_screen) * 256 - 720 * 128
		+ data->utils.sprite_height * 128;
	data->utils.tex_y = ((data->utils.d * tex.height)
			/ data->utils.sprite_height) / 256;
	if (tex.addr[data->utils.tex_y * tex.line_length + data->utils.tex_x
			* (tex.bits_per_pixel / 8)])
	{
		data->utils.poss = data->utils.tex_y * tex.line_length
			+ data->utils.tex_x * (tex.bits_per_pixel / 8);
		my_mlx_pixel_put(data, data->utils.stripe, y,
			create_trgb(0,
				(int)(unsigned char)tex.addr[data->utils.poss + 2],
				(int)(unsigned char)tex.addr[data->utils.poss + 1],
				(int)(unsigned char)tex.addr[data->utils.poss]));
	}
}

void	utils_stripe_while(t_data *data, t_text *texture, t_sprites *tmp)
{
	t_text	tex;
	int		y;

	y = 0;
	tex = texture[4];
	while (data->utils.stripe < data->utils.draw_end_x)
	{
		data->utils.tex_x = (int)(256 * (data->utils.stripe
					- (-data->utils.sprite_width
						/ 2 + data->utils.sprite_screen_x))
				* tex.width / data->utils.sprite_width) / 256;
		if (data->utils.transform_y > 0 && data->utils.stripe > 0
			&& data->utils.stripe < 720
			&& data->utils.transform_y < tmp->zbuffer[data->utils.stripe])
		{
			y = data->utils.draw_start_y;
			while (y < data->utils.draw_end_y)
			{
				pixel_put_sp(data, texture, y);
				y++;
			}
		}
		data->utils.stripe++;
	}
}

void	print_sprites(t_data *data, t_text *texture, t_sprites *tmp)
{
	tmp = data->sprites;
	while (tmp)
	{
		init_sp(data, tmp);
		utils_stripe_while(data, texture, tmp);
		tmp = tmp->next;
	}
}
