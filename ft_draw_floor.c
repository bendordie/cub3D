/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 19:10:08 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 02:34:24 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_draw_floor(t_all *all)
{
	int	x;
	int	y;

	y = all->screen_height / 2;
	while (y < all->screen_height)
	{
		x = 0;
		while (x < all->screen_width)
		{
			ft_mlx_pixel_put(&(all->image), x, y, all->color_floor);
			x++;
		}
		y++;
	}
}
