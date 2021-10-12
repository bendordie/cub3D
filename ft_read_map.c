/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:14:25 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 19:05:05 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_free_line(char **line)
{
	free(*line);
	return (1);
}

int		ft_set_arguments(t_all *all, char **argument)
{
	if (!argument[0])
		return (ft_str_free(argument));
	if (!ft_strncmp(argument[0], "R", 1))
		return (ft_set_resolution(all, argument));
	if (!ft_strncmp(argument[0], "NO", 2))
		return (ft_set_north_texture(all, argument));
	if (!ft_strncmp(argument[0], "EA", 2))
		return (ft_set_east_texture(all, argument));
	if (!ft_strncmp(argument[0], "SO", 2))
		return (ft_set_south_texture(all, argument));
	if (!ft_strncmp(argument[0], "WE", 2))
		return (ft_set_west_texture(all, argument));
	if (!ft_strncmp(argument[0], "S", 1))
		return (ft_set_sprite_texture(all, argument));
	if (!ft_strncmp(argument[0], "F", 1))
		return (ft_set_floor_color(all, argument));
	if (!ft_strncmp(argument[0], "C", 1))
		return (ft_set_ceil_color(all, argument));
	return (0);
}

int		ft_parse_line(t_all *all, char **line)
{
	char	**argument;

	argument = ft_split(*line, ' ');
	if (*line[0] == ' ' && argument[0][0] != '1')
		ft_error("Error: Line starts with invalid char");
	if (!argument[0] && all->begin_map_reading == 1)
		ft_error("Error: Map has a gap inside or after it");
	if (ft_set_arguments(all, argument))
		return (ft_free_line(line));
	if (all->color_ceil < 0 || all->color_floor < 0
			|| !all->tex_north.img || !all->tex_west.img
			|| !all->tex_east.img || !all->tex_south.img || !all->sprite.img)
		ft_error("Error: Missing parameters");
	all->begin_map_reading = 1;
	ft_str_free(argument);
	return (0);
}

int		ft_read_map(t_all *all, char *map_file)
{
	int		fd;
	int		gnl;
	char	*line;
	t_list	*head;

	line = NULL;
	head = NULL;
	fd = open(map_file, O_RDONLY);
	while ((gnl = get_next_line(fd, &line)))
	{
		if (gnl < 0)
			ft_error("Error: Something goes wrong with GNL");
		if (ft_parse_line(all, &line) && !all->begin_map_reading)
			continue ;
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	if (line[0] == '1' || line[0] == ' ')
		ft_lstadd_back(&head, ft_lstnew(line));
	else
		free(line);
	all->map = ft_make_map(&head, ft_lstsize(head));
	ft_list_clear(&head);
	close(fd);
	return (0);
}
