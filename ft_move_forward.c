/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_forward.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:37:04 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 03:29:29 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_move_forward(t_all *all)
{
	all->plr.x += 0.25 * cos(all->plr.dir);
	all->plr.y += 0.25 * sin(all->plr.dir);
	if (all->map[(int)(all->plr.y + 0.35 * sin(all->plr.dir))]
			[(int)(all->plr.x + 0.35 * cos(all->plr.dir))] == '1'
			|| all->map[(int)(all->plr.y + 0.35 * sin(all->plr.dir))]
			[(int)(all->plr.x + 0.35 * cos(all->plr.dir))] == '2'
			|| all->map[(int)(all->plr.y + 0.35 * sin(all->plr.dir))]
			[(int)(all->plr.x + 0.35 * cos(all->plr.dir))] == '3')
	{
		all->plr.x -= 0.25 * cos(all->plr.dir);
		all->plr.y -= 0.25 * sin(all->plr.dir);
	}
}
