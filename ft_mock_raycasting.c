/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mock_raycasting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 00:39:47 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 03:26:09 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_save_spr_left(t_all *all, t_ray *ray)
{
	int		n;
	double	radius;
	double	x;
	double	y;

	n = 0;
	x = (int)(ray->x) + 0.5;
	y = (int)(ray->y) + 0.5;
	radius = sqrt(pow(x - ray->x, 2) + pow(y - ray->y, 2));
	if (radius >= 0.49 && radius <= 0.51)
	{
		ray->x0 = (int)(ray->x);
		ray->y0 = (int)(ray->y);
		while (n < all->spr_n)
		{
			if (all->s[n]->c_x == (int)(ray->x)
					&& all->s[n]->c_y == (int)(ray->y))
				break ;
			n++;
		}
		all->s[n]->x_cut_l++;
	}
}

void	ft_save_spr_mid(t_all *all, t_ray *ray, int x_screen)
{
	int		n;
	double	radius;
	double	x;
	double	y;

	n = 0;
	x = (int)(ray->x) + 0.5;
	y = (int)(ray->y) + 0.5;
	radius = sqrt(pow(x - ray->x, 2) + pow(y - ray->y, 2));
	if (radius >= 0.49 && radius <= 0.51)
	{
		ray->x0 = (int)(ray->x);
		ray->y0 = (int)(ray->y);
		while (n < all->spr_n)
		{
			if (all->s[n]->c_x == (int)(ray->x)
					&& all->s[n]->c_y == (int)(ray->y))
				break ;
			n++;
		}
		if (all->s[n]->x_inv < 0)
			all->s[n]->x_inv = x_screen;
		all->s[n]->x_cut_m++;
	}
}

void	ft_cast_mock_rays(t_all *all, t_ray *ray,
							double ray_left, double ray_right)
{
	int     x;
	double  x_offset;
	double  y_offset;

	x = 0;
	while (ray_left < ray_right)
	{
		ray->x = all->plr.x;
		ray->y = all->plr.y;
		ray->x0 = 0;
		ray->y0 = 0;
		x_offset = 0.01 * cos(ray_left);
		y_offset = 0.01 * sin(ray_left);
		while (all->map[(int)(ray->y)][(int)(ray->x)] != '1')
		{
			ray->x += x_offset;
			ray->y += y_offset;
			if (all->map[(int)(ray->y)][(int)(ray->x)] == '2'
					&& ((int)(ray->y) != ray->y0 || (int)(ray->x) != ray->x0))
			{
				if (ray_right == all->plr.dir - M_PI / 6)
					ft_save_spr_left(all, ray);
				if (ray_right == all->plr.dir + M_PI / 6)
					ft_save_spr_mid(all, ray, x);
			}
		}
		ray_left += (M_PI / 3) / all->screen_width;
		x++;
	}
}
