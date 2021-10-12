/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 01:35:15 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 03:02:27 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_draw_line(t_all *all, int x, int wall, double mx)
{
	int		color;
	int		start;
	int		end;
	double	ny;
	double	k;

	ny = 0.0;
	k = (double)((double)all->temp->hei / (double)wall);
	start = all->screen_height / 2 - wall / 2;
	end = all->screen_height / 2 + wall / 2;
	while (start < end)
	{
		if (start >= 0)
		{
			color = ft_get_tex_color(all->temp, mx, ny);
			ft_mlx_pixel_put(&(all->image), x, start++, color);
			ny += k;
		}
		else
		{
			start++;
			end--;
			ny += k;
		}
	}
}

void	ft_draw_wall_line(t_all *all, int x, int wall, t_ray *ray)
{
	double	mx;

	if (ray->side == 1)
	{
		mx = fabs(((ray->x) - (int)(ray->x)) * all->tex_north.wid);
		all->temp = &(all->tex_north);
	}
	else if (ray->side == 2)
	{
		mx = fabs(((ray->y) - (int)(ray->y)) * all->tex_east.wid);
		all->temp = &(all->tex_east);
	}
	else if (ray->side == 3)
	{
		mx = all->tex_south.wid
			- fabs(((ray->x) - (int)(ray->x)) * all->tex_south.wid);
		all->temp = &(all->tex_south);
	}
	else if (ray->side == 4)
	{
		mx = all->tex_west.wid
			- fabs(((ray->y) - (int)(ray->y)) * all->tex_west.wid);
		all->temp = &(all->tex_west);
	}
	ft_draw_line(all, x, wall, mx);
}

void	ft_draw_walls(t_all *all)
{
	int		x;
	double	ray_left;
	double	ray_right;
	double	ray_len;
	t_ray	ray;

	x = 0;
	ray_left = all->plr.dir - M_PI / 6;
	ray_right = all->plr.dir + M_PI / 6;
	ray.x = all->plr.x;
	ray.y = all->plr.y;
	ray.dir = all->plr.dir;
	while (ray_left <= ray_right)
	{
		ray.x = all->plr.x;
		ray.y = all->plr.y;
		ray_len = ft_calc_ray_len(all, &ray, ray_left, x);
		ray_len = ray_len * fabs(cos(all->plr.dir - ray_left));
		if (x < all->screen_width)
			ft_draw_wall_line(all, x++, all->screen_width / ray_len, &ray);
		ray_left += (M_PI / 3) / all->screen_width;
	}
	if (all->spr_n > 0 && all->spr_draw)
		ft_draw_sprites(all);
}
