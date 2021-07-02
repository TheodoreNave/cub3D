/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:05:33 by tnave             #+#    #+#             */
/*   Updated: 2021/06/27 22:12:05 by tnave            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include "../mlx/mlx.h"

# define BUFFER_SIZE 32
# define RGB_MAX 255
# define RGB_MIN 0
# define ROTATE_LEFT 65361
# define ROTATE_RIGHT 65363
# define FORWARD_W 119
# define BACK_S 115
# define LEFT_A 97
# define RIGHT_D 100
# define ESC 65307
# define OPEN_MAP 109

typedef struct s_parse_list
{
	void					*content;
	struct s_parse_list		*next;

}	t_parse_list;

typedef struct s_slist
{
	int						x;
	int						y;
	double					*zbuffer;
	int						order;
	double					distance;
	struct s_slist			*next;

}	t_sprites;

typedef struct s_utils
{
	double					sprite_x;
	double					sprite_y;
	double					inv_det;
	double					transform_x;
	double					transform_y;
	int						sprite_screen_x;
	int						v_move_screen;
	int						sprite_height;
	int						draw_start_y;
	int						draw_end_y;
	int						sprite_width;
	int						draw_start_x;
	int						draw_end_x;
	int						stripe;
	int						tex_x;
	int						d;
	int						tex_y;
	int						poss;

}	t_utils;

typedef struct s_floor
{
	float					ray_dirx_zero;
	float					ray_diry_zero;
	float					ray_dirx_one;
	float					ray_diry_one;
	float					row_distance;
	float					floor_step_x;
	float					floor_step_y;
	float					floor_x;
	float					floor_y;
	int						cell_x;
	int						cell_y;
	int						tx;
	int						ty;
	int						i;

}	t_floor;

typedef struct s_sky
{
	float					ray_dirx_zero;
	float					ray_diry_zero;
	float					ray_dirx_one;
	float					ray_diry_one;
	float					row_distance;
	float					floor_step_x;
	float					floor_step_y;
	float					floor_x;
	float					floor_y;
	int						cell_x;
	int						cell_y;
	int						tx;
	int						ty;
	int						i;

}	t_sky;

typedef struct s_color
{
	int						t;
	int						r;
	int						g;
	int						b;

}	t_color;

typedef struct s_mappy
{
	int						index_map;
	int						map_height;
	int						map_width;
	int						nb_lignes;
	int						nl;
	int						map_size;
	int						x_end;
	int						y_end;
	char					**map;

}	t_mappy;

typedef struct s_img
{
	void					*img;
	char					*addr;
	int						bits_per_pixel;
	int						line_length;
	int						endian;

}	t_img;

typedef struct s_text
{
	void					*img;
	char					*addr;
	int						bits_per_pixel;
	int						line_length;
	int						endian;
	int						width;
	int						height;
	double					wallx;
	int						tex_x;
	int						tex_y;
	double					step;
	double					texpos;

}	t_text;

typedef struct s_ray
{
	double					pos_x;
	double					pos_y;
	double					dir_x;
	double					dir_y;
	double					plane_x;
	double					plane_y;
	int						w;
	int						h;
	double					camera_x;
	double					rdx;
	double					rdy;
	int						map_x;
	int						map_y;
	double					side_dist_x;
	double					side_dist_y;
	double					delta_dist_x;
	double					delta_dist_y;
	double					perp_wall_dist;
	int						step_x;
	int						step_y;
	int						hit;
	int						side;
	int						line_height;
	int						draw_start;
	int						draw_end;
	double					movespeed;
	double					frametime;
	double					rotspeed;
	char					start;
	int						pdx;
	int						pdy;
	int						pa;
	int						all_y;
	int						all_x;
	int						all_pos;
	double					old_dir_x;
	double					old_plane_x;

}	t_ray;

typedef struct s_keys
{
	int						forward;
	int						back;
	int						left;
	int						right;
	int						rotate_left;
	int						rotate_right;

}	t_keys;

typedef struct s_data
{
	int						fd;
	char					**parsing;
	int						count;
	int						count_params;
	char					*no;
	char					*so;
	char					*we;
	char					*ea;
	char					*s;
	char					**virgule;
	int						texdir;
	void					*mlx;
	void					*win;
	void					*image;
	int						refresh;
	int						map_key;
	int						tmpp;
	t_sprites				*sprites;
	t_utils					utils;
	t_floor					earth;
	t_sky					sky;
	t_ray					*ray;
	t_parse_list			*parse;
	t_color					floor;
	t_color					ceilling;
	t_mappy					mappy;
	t_img					img;
	t_text					*texture;
	t_keys					keys;

}	t_data;

void			*ft_memset(void *b, int c, size_t len);

void			ft_lstadd_back(t_parse_list **alst, t_parse_list *new);

t_parse_list	*ft_lstnew(void *content);

int				ft_lstsize(t_parse_list *lst);

int				parsing_all_data(t_parse_list **parse, t_data *data);

int				parsing_textures_id(t_data *data);

int				parsing_rgb_id(t_data *data);

int				ft_one(char *str);

void			free_split(char **tab);

int				ft_error(int i, char *str, t_data *data);

int				ft_strequ(char *s1, char *s2);

int				parse_textures(char **tab, t_data *data);

void			error_parameters(t_data *data);

int				parse_rgb(char **tab, t_data *data, t_color *type);

int				ft_digit_virgule(char **tab, t_data *data);

int				count_len_split(char **str);

int				count_char_in_string(char *str, char c);

int				parse_map(t_data *data, t_parse_list *tmp);

int				is_valid_map(t_data *data, t_ray *ray);

int				char_in_string(char *str, char c);

void			map_check_error(t_data *data, t_parse_list *tmp);

void			check_first_and_final_line(char *line, t_data *data);

void			check_one_first_char(char *line, t_data *data);

int				is_valid_char_in_map(char c);

void			final_flash(t_data *data, t_ray *ray);

int				all_elements(t_data *data, t_ray *ray);

int				start_position(char c);

int				is_valid_char(char c);

void			check_wall(char **map, int x, int y, t_data *data);

void			let_def_position(t_ray *ray);

t_sprites		*lstnew_sprites(int x, int y);

void			lstadd_back_slist(t_sprites **lst, t_sprites *new);

int				ft_lstsize_slist(t_sprites *lst);

void			ft_lstclear_parse(t_parse_list **lst, void (*del)(void *));

void			ft_lstclear_sprites(t_sprites **lst, void (*del)(void *));

int				ft_refresh(t_data *data, t_text *texture);

int				exit_function(t_data *data);

int				key_hook_rotate_right(t_data *data);

int				key_hook_rotate_left(t_data *data);

int				key_hook_backward(t_data *data);

int				key_hook_forward(t_data *data);

int				key_map(t_data *data);

int				key_hook(int keycode, t_data *data);

int				key_hook_left(t_data *data);

int				key_hook_right(t_data *data);

int				key_hook_end(int keycode, t_data *data);

void			raycasting(t_data *data, t_text *texture);

void			raycasting_one(t_data *data, t_ray *ray);

void			raycasting_two(t_ray *ray);

void			dda_calcul(t_ray *ray, t_data *data);

void			raycasting_last(t_ray *ray);

void			ft_verline(int x, t_data *data, t_text *texture);

void			ft_screen(t_data *data);

void			drawSquare(t_data *data, int x, int y);

void			drawSquareblack(t_data *data, int x, int y);

void			drawMap2D(t_data *data);

void			draw_player(t_ray *ray, t_data *data);

void			draw_line(t_ray *ray, t_data *data, int x, int y);

void			choose_ray(t_data *data, t_text *texture);

void			add_texture(t_text *texture);

void			ft_texture(t_data *data, t_text *texture);

void			draw_text(t_data *data, t_text *texture, int x, int y);

void			mlx_1138(t_data *data, t_text *texture);

char			*ft_strjoin_free(char *s1, char *s2);

char			*get_str_new_line(char *new_line);

int				get_next_line(int fd, char **line);

size_t			ft_strlen(const char *str);

int				get_len(char *str);

char			*ft_strdup(const char *s1);

char			*ft_substr(char const *s, unsigned int start, size_t len);

char			*ft_strchr(const char *s, int c);

int				create_trgb(int t, int r, int g, int b);

int				my_create_trgb(t_color color);

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

void			mini_map(t_data *data);

void			ray_init(t_data *data);

void			sky_text(int y, t_data *data, t_text *texture);

void			floor_text(int y, t_data *data, t_text *texture);

void			ft_sprite(t_data *data, t_text *texture);

int				ft_check(char c, char *str);

int				ft_word_count_charset(char *str, char *charset);

int				full_word_length(char *str, int k, char *charset);

char			*new_full_string_charset(char *str, int l, int size);

char			**ft_split_charset(char *str, char *charset);

int				ft_atoi(const char *str);

char			**ft_split(char const *s, char c);

char			*ft_strdup(const char *s1);

int				str_is_digit(char *str);

void			swap_tmp(t_sprites *tmp, t_sprites *tmp2);

void			sorting_sprites(t_sprites **lst);

int				parse_file(char *str, t_data *data);

int				valid_file(char *str, t_data *data);

void			ft_text_sky_floor(t_data *data, t_text *texture);

void			ft_texture_part_two(t_data *data, t_text *texture);

void			free_all_tabs(t_data *data);

void			ft_clear_image(t_data *data);

void			swap_tmp(t_sprites *tmp, t_sprites *tmp2);

void			sorting_sprites(t_sprites **lst);

void			init_sp_two(t_data *data);

void			init_sp(t_data *data, t_sprites *tmp);

void			pixel_put_sp(t_data *data, t_text *texture, int y);

void			utils_stripe_while(t_data *data, t_text *texture,
					t_sprites *tmp);
void			print_sprites(t_data *data, t_text *texture, t_sprites *tmp);

void			nice_type(t_data *data, t_color *type);

#endif
