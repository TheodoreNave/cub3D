/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:36:44 by tnave             #+#    #+#             */
/*   Updated: 2021/07/02 11:27:57 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	add_texture(t_text *texture)
{
	texture[0].addr = mlx_get_data_addr(texture[0].img,
			&texture[0].bits_per_pixel, &texture[0].line_length,
			&texture[0].endian);
	texture[1].addr = mlx_get_data_addr(texture[1].img,
			&texture[1].bits_per_pixel, &texture[1].line_length,
			&texture[1].endian);
	texture[2].addr = mlx_get_data_addr(texture[2].img,
			&texture[2].bits_per_pixel, &texture[2].line_length,
			&texture[2].endian);
	texture[3].addr = mlx_get_data_addr(texture[3].img,
			&texture[3].bits_per_pixel, &texture[3].line_length,
			&texture[3].endian);
}

void	ft_texture(t_data *data, t_text *texture)
{
	texture[0].img = mlx_xpm_file_to_image(data->mlx, data->no,
			&(texture[0].width), &(texture[0].height));
	if (!texture[0].img)
		ft_error(0, "Error No\n", data);
	texture[1].img = mlx_xpm_file_to_image(data->mlx, data->so,
			&(texture[1].width), &(texture[1].height));
	if (!texture[1].img)
		ft_error(0, "Error So\n", data);
	texture[2].img = mlx_xpm_file_to_image(data->mlx, data->we,
			&(texture[2].width), &(texture[2].height));
	if (!texture[2].img)
		ft_error(0, "Error We\n", data);
	texture[3].img = mlx_xpm_file_to_image(data->mlx, data->ea,
			&(texture[3].width), &(texture[3].height));
	if (!texture[3].img)
		ft_error(0, "Error Ea\n", data);
}

void	draw_text(t_data *data, t_text *texture, int x, int y)
{
	t_text	tex;
	int		i;

	y = y - 1;
	tex = texture[data->texdir];
	tex.step = 1.0 * tex.height / data->ray->line_height;
	tex.tex_x = (int)(tex.wallx * (double)tex.width);
	if (data->ray->side == 0 && data->ray->rdx > 0)
		tex.tex_x = tex.width - tex.tex_x - 1;
	if (data->ray->side == 1 && data->ray->rdy < 0)
		tex.tex_x = tex.width - tex.tex_x - 1;
	tex.texpos = (y - data->ray->h / 2 + data->ray->line_height / 2) * tex.step;
	while (++y <= data->ray->draw_end)
	{
		tex.texpos += tex.step;
		tex.tex_y = (int)tex.texpos & (tex.height - 1);
		i = tex.tex_y * tex.line_length + tex.tex_x * (tex.bits_per_pixel / 8);
		if (y < data->ray->h && x < data->ray->w)
		{
			my_mlx_pixel_put(data, x, y, create_trgb(0,
					(int)(unsigned char)tex.addr[i + 2],
					(int)(unsigned char)tex.addr[i + 1],
					(int)(unsigned char)tex.addr[i]));
		}
	}
}

void	choose_ray(t_data *data, t_text *texture)
{
	data->texdir = 0;
	if (data->ray->side == 0 && data->ray->rdx < 0)
		data->texdir = 0;
	if (data->ray->side == 0 && data->ray->rdx >= 0)
		data->texdir = 1;
	if (data->ray->side == 1 && data->ray->rdy < 0)
		data->texdir = 2;
	if (data->ray->side == 1 && data->ray->rdy >= 0)
		data->texdir = 3;
	if (data->ray->side == 0)
		texture[data->texdir].wallx = data->ray->pos_y
			+ data->ray->perp_wall_dist * data->ray->rdy;
	else
		texture[data->texdir].wallx = data->ray->pos_x
			+ data->ray->perp_wall_dist * data->ray->rdx;
	texture[data->texdir].wallx -= floor((texture[data->texdir].wallx));
}
