/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:30:43 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 19:52:38 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_render_image(t_all *all)
{
	if (all->image.img)
		mlx_destroy_image(all->mlx, all->image.img);
	all->image.img = mlx_new_image(all->mlx,
			all->screen_width, all->screen_height);
	all->image.addr = mlx_get_data_addr(all->image.img,
			&(all->image.bpp), &(all->image.line_length), &(all->image.endian));
	ft_draw_image(all);
}

int		ft_close_win(t_all *all)
{
	mlx_destroy_image(all->mlx, all->image.img);
	exit(0);
}

int		ft_key_press(int key, t_all *all)
{
	int	i;

	i = -1;
	if (key == 13)
		ft_move_forward(all);
	if (key == 1)
		ft_move_back(all);
	if (key == 0)
		ft_move_left(all);
	if (key == 2)
		ft_move_right(all);
	if (key == 123)
		all->plr.dir -= M_PI / 60;
	if (key == 124)
		all->plr.dir += M_PI / 60;
	if (key == 53)
		exit(0);
	all->plr.dir = ft_limit_angle(all->plr.dir);
	while (++i < all->spr_n)
		ft_clear_spr_data(all, i);
	ft_render_image(all);
	mlx_put_image_to_window(all->mlx, all->win, all->image.img, 0, 0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_all	all;

	if (argc == 2 || argc == 3)
	{
		all.mlx = mlx_init();
		ft_data_processing(&all, argv[1]);
		all.win = mlx_new_window(all.mlx, all.screen_width,
				all.screen_height, "cube");
		ft_render_image(&all);
		if (argc == 3)
		{
			if (!ft_strncmp(argv[2], "--save", 6))
				ft_take_screenshot(&all);
			else
				ft_error("Error: Try to write '--save' as the second argument");
		}
		mlx_put_image_to_window(all.mlx, all.win, all.image.img, 0, 0);
		mlx_hook(all.win, 2, (1L << 0), ft_key_press, &all);
		mlx_hook(all.win, 17, (1L << 0), ft_close_win, &all);
		mlx_loop(all.mlx);
	}
	else
		ft_error("Error: Wrong number of arguments");
	return (0);
}
