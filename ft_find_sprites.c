/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:39:28 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 03:07:53 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_find_sprites(t_all *all)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			if (all->map[i][j] == '2')
			{
				ft_add_new_sprite(all, j, i, count);
				count++;
			}
			j++;
		}
		i++;
	}
}
