/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 00:42:59 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 19:01:46 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_define_current_sprite(t_all *all, t_ray *ray)
{
	int	n;

	n = 0;
	while (n < all->spr_n)
	{
		if (all->s[n]->c_x == (int)(ray->x)
				&& all->s[n]->c_y == (int)(ray->y))
			break ;
		n++;
	}
	return (n);
}

void	ft_find_side(t_ray *ray, double ray_left, int sin)
{
	ray_left = ft_limit_angle(ray_left);
	if (sin == 0)
	{
		if ((ray_left >= 3 * M_PI / 2 && ray_left < M_PI * 2)
				|| (ray_left >= M_PI && ray_left < 3 * M_PI / 2))
			ray->side = 1;
		else
			ray->side = 3;
	}
	if (sin == 1)
	{
		if ((ray_left >= 3 * M_PI / 2 && ray_left < M_PI * 2)
				|| (ray_left >= 0 && ray_left < M_PI / 2))
			ray->side = 2;
		else
			ray->side = 4;
	}
}

void	ft_save_spr_data(t_all *all, t_ray *ray, int x_screen)
{
	int		n;
	double	radius;
	double	x;
	double	y;

	x = (int)(ray->x) + 0.5;
	y = (int)(ray->y) + 0.5;
	radius = sqrt(pow(x - ray->x, 2) + pow(y - ray->y, 2));
	if (radius >= 0.49 && radius <= 0.51)
	{
		ray->x0 = (int)(ray->x);
		ray->y0 = (int)(ray->y);
		n = ft_define_current_sprite(all, ray);
		all->s[n]->x[all->s[n]->x_count] = x_screen;
		all->s[n]->x_count += 1;
		all->s[n]->dist = sqrt(pow(x - all->plr.x, 2) + pow(y - all->plr.y, 2));
		all->s[n]->h = (double)(all->screen_width / all->s[n]->dist);
		all->spr_draw = 1;
	}
}

void	ft_cast_wall_ray(t_all *all, t_ray *ray,
							double ray_left, int x_screen)
{
    double  x_offset;
    double  y_offset;

	ray->x0 = 0;
	ray->y0 = 0;
	x_offset = 0.005 * cos(ray_left);
	y_offset = 0.005 * sin(ray_left);
	while (1)
	{
		if (all->map[(int)(ray->y)][(int)(ray->x)] != '1' &&
				all->map[(int)(ray->y)][(int)(ray->x)] != '3')
			ray->x += x_offset;
		else
			return (ft_find_side(ray, ray_left, 0));
		if (all->map[(int)(ray->y)][(int)(ray->x)] != '1' &&
				all->map[(int)(ray->y)][(int)(ray->x)] != '3')
			ray->y += y_offset;
		else
			return (ft_find_side(ray, ray_left, 1));
		if (all->map[(int)(ray->y)][(int)(ray->x)] == '2'
				&& ((int)(ray->y) != ray->y0
					|| (int)(ray->x) != ray->x0))
			ft_save_spr_data(all, ray, x_screen);
	}
}

double	ft_calc_ray_len(t_all *all, t_ray *ray,
							double ray_left, int x_screen)
{
	double	ray_len;

	ft_cast_wall_ray(all, ray, ray_left, x_screen);
	ray_len = sqrt(pow(all->plr.x - ray->x, 2)
			+ pow(all->plr.y - ray->y, 2));
	return (ray_len);
}
