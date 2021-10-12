/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_ceil_floor_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 21:54:32 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 19:26:54 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_count_comma(char *argument)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (argument[i])
	{
		if (argument[i] == ',')
			count++;
		i++;
	}
	if (count > 2)
		ft_error("Error: Too many commas in color argument");
}

int		ft_set_ceil_color(t_all *all, char **argument)
{
	int		i;
	int		r;
	int		g;
	int		b;
	char	**color;

	i = -1;
	ft_count_comma(argument[1]);
	if (all->color_ceil >= 0)
		ft_error("Error: Duplicate ceil color set");
	if (argument[2])
		ft_error("Error: Ceil color value has wrong number of arguments");
	color = ft_split(argument[1], ',');
	while (color[++i])
	{
		if (!ft_str_isdigit(color[i]))
			ft_error("Error: Ceil color value has non-digital symbols");
	}
	if ((r = ft_atoi(color[0])) > 255
			|| (g = ft_atoi(color[1])) > 255
			|| (b = ft_atoi(color[2])) > 255)
		ft_error("Error: Invalid ceil color set (over 255)");
	all->color_ceil = ft_get_rgb_color(r, g, b);
	return (ft_str_free(argument) && ft_str_free(color));
}

int		ft_set_floor_color(t_all *all, char **argument)
{
	int		i;
	int		r;
	int		g;
	int		b;
	char	**color;

	i = -1;
	ft_count_comma(argument[1]);
	if (all->color_floor >= 0)
		ft_error("Error: Duplicate floor color set");
	if (argument[2])
		ft_error("Error: Floor color value has wrong number of arguments");
	color = ft_split(argument[1], ',');
	while (color[++i])
	{
		if (!ft_str_isdigit(color[i]))
			ft_error("Error: Floor color value has non-digital symbols");
	}
	if ((r = ft_atoi(color[0])) > 255
			|| (g = ft_atoi(color[1])) > 255
			|| (b = ft_atoi(color[2])) > 255)
		ft_error("Error: Invalid floor color set (over 255)");
	all->color_floor = ft_get_rgb_color(r, g, b);
	return (ft_str_free(argument) && ft_str_free(color));
}
