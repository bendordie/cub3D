/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_valid_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 20:10:29 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 20:18:19 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_check_invalid_cell(char **map, int i, int j, char c)
{
	if ((map[i][j] == c && (i == 0 || j == 0))
			|| (map[i][j] == c && (!map[i + 1] || !map[i][j + 1]))
			|| ((map[i][j] == c && map[i + 1] != 0 && map[i][j + 1] != 0)
				&& ((map[i - 1][j] != '0'
						&& map[i - 1][j] != '1' && map[i - 1][j] != '2')
					|| (map[i - 1][j + 1] != '0'
						&& map[i - 1][j + 1] != '1' && map[i - 1][j + 1] != '2')
					|| (map[i][j + 1] != '0'
						&& map[i][j + 1] != '1' && map[i][j + 1] != '2')
					|| (map[i + 1][j + 1] != '0'
						&& map[i + 1][j + 1] != '1' && map[i + 1][j + 1] != '2')
					|| (map[i + 1][j] != '0'
						&& map[i + 1][j] != '1' && map[i + 1][j] != '2')
					|| (map[i + 1][j - 1] != '0'
						&& map[i + 1][j - 1] != '1' && map[i + 1][j - 1] != '2')
					|| (map[i][j - 1] != '0'
						&& map[i][j - 1] != '1' && map[i][j - 1] != '2')
					|| (map[i - 1][j - 1] != '0'
						&& map[i - 1][j - 1] != '1'
						&& map[i - 1][j - 1] != '2'))))
		return (1);
	else
		return (0);
}

void	ft_spaces_behind_validation(char **map)
{
	int	i;
	int	end;

	i = 0;
	while (map[i])
	{
		end = ft_strlen(map[i]) - 1;
		if (map[i][end] == ' ')
			ft_error("Error: Spaces at the end of the map line");
		i++;
	}
}

void	ft_char_validation(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N'
					&& map[i][j] != '2' && map[i][j] != ' ')
				ft_error("Error: Map has an invalid char");
			j++;
		}
		i++;
	}
}

void	ft_space_validation(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_check_invalid_cell(map, i, j, '0'))
				ft_error("Error: Player/spaces inside the map border");
			j++;
		}
		i++;
	}
}

void	ft_sprite_validation(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_check_invalid_cell(map, i, j, '2'))
				ft_error("Error: Invalid map, sprite inside the map border");
			j++;
		}
		i++;
	}
}
