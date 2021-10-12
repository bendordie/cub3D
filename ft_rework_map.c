/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rework_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:19:02 by cshells           #+#    #+#             */
/*   Updated: 2021/02/16 00:17:53 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_check_char(char c)
{
	int		i;
	char	*s;

	i = 0;
	s = "0123";
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_cell(char **map, int i, int j)
{
	if (i != 0 && j != 0 && map[i][j] == '1'
			&& map[i + 1] != 0 && map[i][j + 1] != 0
			&& (ft_check_char(map[i - 1][j]))
			&& (ft_check_char(map[i - 1][j + 1]))
			&& (ft_check_char(map[i][j + 1]))
			&& (ft_check_char(map[i + 1][j + 1]))
			&& (ft_check_char(map[i + 1][j]))
			&& (ft_check_char(map[i + 1][j - 1]))
			&& (ft_check_char(map[i][j - 1]))
			&& (ft_check_char(map[i - 1][j - 1]))
			&& (j < ft_strlen(map[i + 1]) && j < ft_strlen(map[i - 1])))
		return (1);
	else
		return (0);
}

void	ft_rework_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_check_cell(map, i, j))
				map[i][j] = '3';
			j++;
		}
		i++;
	}
}
