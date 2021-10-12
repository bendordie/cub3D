/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:16:41 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 21:33:21 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "minilibx_mms/mlx.h"

typedef struct		s_s {
	int				*x;
	int				x_inv;
	int				x_count;
	int				c_x;
	int				c_y;
	int				h;
	int				x_cut_l;
	int				x_cut_m;
	double			dist;
}					t_s;

typedef struct		s_spr_info
{
	int				start_y;
	int				end_y;
	double			k;
	double			mx;
	double			mx_step;
}					t_spr_info;

typedef struct		s_ray
{
	int				side;
	double			x;
	double			y;
	double			x0;
	double			y0;
	double			dir;
}					t_ray;

typedef struct		s_plr
{
	double			x;
	double			y;
	double			dir;
}					t_plr;

typedef struct		s_image
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				hei;
	int				wid;
}					t_image;

typedef struct		s_all
{
	int				color_ceil;
	int				color_floor;
	int				screen_width;
	int				screen_height;
	int				spr_draw;
	int				begin_map_reading;
	int				spr_n;
	void			*mlx;
	void			*win;
	char			**map;
	t_plr			plr;
	t_image			image;
	t_image			sprite;
	t_image			tex_north;
	t_image			tex_west;
	t_image			tex_east;
	t_image			tex_south;
	t_image			*temp;
	t_s				**s;
}					t_all;

int					ft_check_invalid_cell(char **map, int i, int j, char c);
int					ft_parse_map(t_all *all);
int					ft_get_rgb_color(int red, int green, int blue);
int					ft_get_tex_color(t_image *tex, int x, int y);
int					ft_map_validation(char **map);
int					ft_read_map(t_all *all, char *map_file);
int					ft_set_ceil_color(t_all *all, char **argument);
int					ft_set_floor_color(t_all *all, char **argument);
int					ft_set_resolution(t_all *all, char **argument);
int					ft_set_east_texture(t_all *all, char **argument);
int					ft_set_north_texture(t_all *all, char **argument);
int					ft_set_south_texture(t_all *all, char **argument);
int					ft_set_west_texture(t_all *all, char **argument);
int					ft_set_sprite_texture(t_all *all, char **argument);
int					ft_str_free(char **str);
int					ft_str_isdigit(char *str);
char				**ft_make_map(t_list **head, int size);
void				ft_add_new_sprite(t_all *all,
										double x, double y, int count);
void				ft_cast_mock_rays(t_all *all, t_ray *ray,
										double ray_left, double ray_right);
void				ft_clear_spr_data(t_all *all, int i);
void				ft_char_validation(char **map);
void				ft_check_extension(char *filename, char *extension);
void				ft_count_sprites(t_all *all);
void				ft_create_spr_struct(t_all *all);
void				ft_data_processing(t_all *all, char *map_file);
void				ft_draw_ceil(t_all *all);
void				ft_draw_floor(t_all *all);
void				ft_draw_image(t_all *all);
void				ft_draw_map(t_all *all);
void				ft_draw_plr(t_all *all);
void				ft_draw_sprites(t_all *all);
void				ft_draw_walls(t_all *all);
void				ft_error(char *err_msg);
void				ft_find_player(t_all *all);
void				ft_find_sprites(t_all *all);
void				ft_list_clear(t_list **begin_list);
void				ft_move_back(t_all *all);
void				ft_move_forward(t_all *all);
void				ft_move_left(t_all *all);
void				ft_move_right(t_all *all);
void				ft_mlx_pixel_put(t_image *image, int x, int y, int color);
void				ft_sort_sprites(t_all *all);
void				ft_space_validation(char **map);
void				ft_spaces_behind_validation(char **map);
void				ft_sprite_validation(char **map);
void				ft_take_screenshot(t_all *all);
void				ft_write_player_data(t_all *all, int x, int y, char dir);
double				ft_calc_ray_len(t_all *all,
											t_ray *ray, double ray_left, int x);
double				ft_limit_angle(double angle);
void				ft_rework_map(char **plan);

#endif
