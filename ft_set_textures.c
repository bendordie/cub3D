/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 21:50:09 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 19:34:39 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_set_north_texture(t_all *all, char **argument)
{
	ft_check_extension(argument[1], ".xpm");
	if (all->tex_north.addr != NULL)
		ft_error("Error: Can't load NORTH texture");
	if (!(all->tex_north.img = mlx_xpm_file_to_image(all->mlx, argument[1],
					&(all->tex_north.wid), &(all->tex_north.hei))))
		ft_error("Error: Can't load NORTH texture");
	all->tex_north.addr = mlx_get_data_addr(all->tex_north.img,
				&(all->tex_north.bpp),
				&(all->tex_north.line_length), &(all->tex_north.endian));
	return (ft_str_free(argument));
}

int		ft_set_east_texture(t_all *all, char **argument)
{
	ft_check_extension(argument[1], ".xpm");
	if (all->tex_east.addr != NULL)
		ft_error("Error: Can't load EAST texture");
	if (!(all->tex_east.img = mlx_xpm_file_to_image(all->mlx, argument[1],
					&(all->tex_east.wid), &(all->tex_east.hei))))
		ft_error("Error: Can't load EAST texture");
	all->tex_east.addr = mlx_get_data_addr(all->tex_east.img,
			&(all->tex_east.bpp), &(all->tex_east.line_length),
			&(all->tex_east.endian));
	return (ft_str_free(argument));
}

int		ft_set_south_texture(t_all *all, char **argument)
{
	ft_check_extension(argument[1], ".xpm");
	if (all->tex_south.addr != NULL)
		ft_error("Error: Can't load SOUTH texture");
	if (!(all->tex_south.img = mlx_xpm_file_to_image(all->mlx, argument[1],
					&(all->tex_south.wid), &(all->tex_south.hei))))
		ft_error("Error: Can't load SOUTH texture");
	all->tex_south.addr = mlx_get_data_addr(all->tex_south.img,
			&(all->tex_south.bpp),
			&(all->tex_south.line_length), &(all->tex_south.endian));
	return (ft_str_free(argument));
}

int		ft_set_west_texture(t_all *all, char **argument)
{
	ft_check_extension(argument[1], ".xpm");
	if (all->tex_west.addr != NULL)
		ft_error("Error: Can't load WEST texture");
	if (!(all->tex_west.img = mlx_xpm_file_to_image(all->mlx, argument[1],
					&(all->tex_west.wid), &(all->tex_west.hei))))
		ft_error("Error: Can't load WEST texture");
	all->tex_west.addr = mlx_get_data_addr(all->tex_west.img,
			&(all->tex_west.bpp),
			&(all->tex_west.line_length), &(all->tex_west.endian));
	return (ft_str_free(argument));
}

int		ft_set_sprite_texture(t_all *all, char **argument)
{
	ft_check_extension(argument[1], ".xpm");
	if (all->sprite.addr != NULL)
		ft_error("Error: Can't load SPRITE texture");
	if (!(all->sprite.img = mlx_xpm_file_to_image(all->mlx, argument[1],
					&(all->sprite.wid), &(all->sprite.hei))))
		ft_error("Error: Can't load SPRITE texture");
	all->sprite.addr = mlx_get_data_addr(all->sprite.img,
			&(all->sprite.bpp),
			&(all->sprite.line_length), &(all->sprite.endian));
	return (ft_str_free(argument));
}
