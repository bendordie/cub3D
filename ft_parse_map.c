/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 00:05:00 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 18:29:47 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_parse_map(t_all *all)
{
	ft_find_player(all);
	ft_map_validation(all->map);
	ft_count_sprites(all);
	if (all->spr_n > 0)
	{
		ft_create_spr_struct(all);
		ft_find_sprites(all);
	}
	ft_rework_map(all->map);
	return (0);
}
