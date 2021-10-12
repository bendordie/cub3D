/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_roof.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 19:14:52 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 02:33:24 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_draw_ceil(t_all *all)
{
	int	x;
	int	y;

	y = 0;
	while (y < all->screen_height / 2)
	{
		x = 0;
		while (x < all->screen_width)
		{
			ft_mlx_pixel_put(&(all->image), x, y, all->color_ceil);
			x++;
		}
		y++;
	}
}
