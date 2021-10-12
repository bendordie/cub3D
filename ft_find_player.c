/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 00:26:36 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 03:06:40 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_find_player(t_all *all)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (all->map[++i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if (all->map[i][j] == 'N' || all->map[i][j] == 'S'
					|| all->map[i][j] == 'E' || all->map[i][j] == 'W')
			{
				count++;
				ft_write_player_data(all, j, i, all->map[i][j]);
				all->map[i][j] = '0';
			}
			j++;
		}
	}
	if (count == 0)
		ft_error("Error: Player not found");
	if (count > 1)
		ft_error("Error: More than 1 player in map");
}
