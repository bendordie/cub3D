/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 22:24:46 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 03:11:46 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	**ft_make_map(t_list **head, int size)
{
	int		i;
	char	**map;
	t_list	*tmp;

	i = 0;
	tmp = *head;
	if (!(map = (char**)ft_calloc(size + 1, sizeof(char*))))
		ft_error("Error: Can't allocate memory for map massive");
	while (tmp)
	{
		map[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (map);
}
