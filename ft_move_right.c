/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 03:05:50 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 03:31:53 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_move_right(t_all *all)
{
	double	dir;

	dir = all->plr.dir + M_PI_2;
	all->plr.x += 0.25 * cos(dir);
	all->plr.y += 0.25 * sin(dir);
	if (all->map[(int)(all->plr.y + 0.35 * sin(dir))]
			[(int)(all->plr.x + 0.35 * cos(dir))] == '1'
			|| all->map[(int)(all->plr.y + 0.35 * sin(dir))]
			[(int)(all->plr.x + 0.35 * cos(dir))] == '2'
			|| all->map[(int)(all->plr.y + 0.35 * sin(dir))]
			[(int)(all->plr.x + 0.35 * cos(dir))] == '3')
	{
		all->plr.x -= 0.25 * cos(dir);
		all->plr.y -= 0.25 * sin(dir);
	}
}
