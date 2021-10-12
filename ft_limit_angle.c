/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_limit_angle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 21:09:14 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 03:09:36 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	ft_limit_angle(double angle)
{
	if (angle < 0)
		return (2 * M_PI + angle);
	else if (angle > 2 * M_PI)
		return (angle - 2 * M_PI);
	else
		return (angle);
}
