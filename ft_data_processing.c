/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_processing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 01:33:54 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 02:31:05 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_set_default_values(t_all *all)
{
	mlx_get_screen_size(all->mlx, &all->screen_width, &all->screen_height);
	all->spr_n = 0;
	all->tex_north.addr = NULL;
	all->tex_east.addr = NULL;
	all->tex_south.addr = NULL;
	all->tex_west.addr = NULL;
	all->sprite.addr = NULL;
	all->color_ceil = -1;
	all->color_floor = -1;
	all->spr_draw = 0;
	all->plr.x = 0;
	all->plr.y = 0;
	all->plr.dir = 0;
	all->begin_map_reading = 0;
}

void	ft_data_processing(t_all *all, char *map_file)
{
	ft_check_extension(map_file, ".cub");
	ft_set_default_values(all);
	ft_read_map(all, map_file);
	ft_parse_map(all);
}
