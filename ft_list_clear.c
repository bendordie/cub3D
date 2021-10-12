/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:26:40 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 03:10:39 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list	*curr;
	t_list	*prev;

	curr = *begin_list;
	if (*begin_list)
	{
		while (curr)
		{
			prev = curr;
			curr = curr->next;
			free(prev);
		}
		*begin_list = 0;
	}
}
