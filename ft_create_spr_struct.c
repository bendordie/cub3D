/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_spr_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 23:17:36 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 02:30:02 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_create_spr_struct(t_all *all)
{
	int	i;

	i = 0;
	if (!(all->s = (t_s**)ft_calloc(all->spr_n + 1, sizeof(t_s*))))
		ft_error("Error: Can't allocate memory for sprites massive");
	while (i < all->spr_n)
	{
		if (!(all->s[i] = (t_s*)ft_calloc(1, sizeof(t_s))))
			ft_error("Error: Can't allocate memory for sprite");
		if (!(all->s[i]->x = (int*)ft_calloc((all->screen_width + 1),
						sizeof(int))))
			ft_error("Error: Can't allocate memory for 'x' massive");
		ft_clear_spr_data(all, i);
		i++;
	}
	all->s[i] = NULL;
}
