/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 21:26:20 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 19:28:33 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_set_resolution(t_all *all, char **argument)
{
	int	i;
	int	width;
	int	height;

	i = 1;
	if (argument[3] || argument[1][0] == '0' || argument[2][0] == '0')
		ft_error("Error: Resolution has invalid number of arguments");
	while (argument[i])
	{
		if (!ft_str_isdigit(argument[i]))
			ft_error("Error: Resolution value has non-digital symbols");
		i++;
	}
	width = ft_atoi(argument[1]);
	height = ft_atoi(argument[2]);
	if (width >= 1 && width <= 1920)
		all->screen_width = width;
	if (height >= 1 && height <= 1080)
		all->screen_height = height;
	return (ft_str_free(argument));
}
