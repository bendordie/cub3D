/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_spr_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 01:29:25 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 02:24:04 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_clear_spr_data(t_all *all, int i)
{
	int	j;

	j = 0;
	all->s[i]->x_count = 0;
	while (j < all->screen_width + 1)
	{
		all->s[i]->x[j] = -1;
		j++;
	}
	all->s[i]->x_inv = -1;
	all->s[i]->h = 0;
	all->s[i]->dist = 0;
	all->s[i]->x_cut_l = 0;
	all->s[i]->x_cut_m = 0;
}
