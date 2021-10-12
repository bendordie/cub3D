/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 02:06:07 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 21:19:01 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_draw_sprite_line(t_all *all, t_spr_info *spr, int x, int t)
{
	int		color;
	double	ny;
	t_image	*tex;

	tex = &(all->sprite);
	ny = 0.0;
	while (spr->start_y < spr->end_y && spr->start_y < all->screen_height)
	{
		if (spr->start_y > 0)
		{
			if (ny < all->sprite.hei - 1)
				color = ft_get_tex_color(tex, spr->mx, ny);
			if (color)
				ft_mlx_pixel_put(&(all->image), x, spr->start_y++, color);
			else
				spr->start_y++;
			ny += spr->k;
		}
		else
		{
			spr->start_y++;
			spr->end_y--;
			ny += spr->k;
		}
	}
}

void	ft_draw_one_sprite(t_all *all, t_spr_info *spr, int t)
{
	int	i;

	i = 0;
	spr->k = (double)((double)all->sprite.hei / (double)all->s[t]->h);
	spr->mx = fabs((double)
			((all->s[t]->x_inv - all->s[t]->x[0] - all->s[t]->x_cut_l)
			/ (double)all->s[t]->h)) * all->sprite.wid;
	spr->mx_step = (double)(all->sprite.wid / (double)all->s[t]->h);
	while (all->s[t]->x[i] >= 0 && i < all->screen_width)
	{
		spr->start_y = (all->screen_height / 2)
										- all->s[t]->h / 2;
		spr->end_y = (all->screen_height / 2)
			+ all->s[t]->h / 2;
		ft_draw_sprite_line(all, spr, all->s[t]->x[i], t);
		spr->mx += spr->mx_step;
		i++;
	}
}

void	ft_draw_sprites(t_all *all)
{
	int			t;
	t_ray		ray;
	t_spr_info	spr;

	t = 0;
	ft_cast_mock_rays(all, &ray,
			all->plr.dir - M_PI / 1.5, all->plr.dir - M_PI / 6);
	ft_cast_mock_rays(all, &ray,
			all->plr.dir - M_PI / 6, all->plr.dir + M_PI / 6);
	ft_sort_sprites(all);
	while (all->s[t])
	{
		if (all->s[t]->h != 0)
			ft_draw_one_sprite(all, &spr, t);
		t++;
	}
	all->spr_draw = 0;
}
