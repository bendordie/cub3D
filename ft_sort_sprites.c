/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 02:40:42 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 19:35:33 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_sort_sprites(t_all *all)
{
	int	i;
	t_s	*buf;

	buf = NULL;
	i = 1;
	while (all->s[i])
	{
		if (all->s[i - 1]->h > all->s[i]->h)
		{
			buf = all->s[i - 1];
			all->s[i - 1] = all->s[i];
			all->s[i] = buf;
			i = 0;
		}
		i++;
	}
}
