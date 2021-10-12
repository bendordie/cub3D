/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tex_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 22:29:38 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 03:08:59 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_get_tex_color(t_image *tex, int x, int y)
{
	int	color;

	color = (*(int *)(tex->addr + ((x + (y * tex->wid)) * (tex->bpp / 8))));
	return (color);
}
