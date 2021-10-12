/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:43:28 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 20:09:30 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_map_validation(char **map)
{
	ft_char_validation(map);
	ft_spaces_behind_validation(map);
	ft_space_validation(map);
	ft_sprite_validation(map);
	return (0);
}
