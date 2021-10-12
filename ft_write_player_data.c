/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_player_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:14:55 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 19:42:04 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_write_player_data(t_all *all, int x, int y, char dir)
{
	all->plr.x = (double)(x + 0.5);
	all->plr.y = (double)(y + 0.5);
	if (dir == 'N')
		all->plr.dir = 3 * M_PI_2;
	else if (dir == 'E')
		all->plr.dir = 2 * M_PI;
	else if (dir == 'S')
		all->plr.dir = M_PI_2;
	else if (dir == 'W')
		all->plr.dir = M_PI;
	else
		all->plr.dir = 3 * M_PI_2;
}
