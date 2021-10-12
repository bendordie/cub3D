/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_screenshot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshells <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:05:04 by cshells           #+#    #+#             */
/*   Updated: 2021/02/12 19:41:15 by cshells          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_write_bmp_header(t_all *all,
		unsigned char *file_h, unsigned char *info_h)
{
	int	file_size;

	file_size = 54 + all->screen_height
		* all->screen_width * all->image.bpp / 8;
	ft_bzero(file_h, 14);
	ft_bzero(info_h, 40);
	file_h[0] = 'B';
	file_h[1] = 'M';
	file_h[2] = (unsigned char)(file_size);
	file_h[3] = (unsigned char)(file_size >> 8);
	file_h[4] = (unsigned char)(file_size >> 16);
	file_h[5] = (unsigned char)(file_size >> 24);
	file_h[10] = (unsigned char)(54);
	info_h[0] = (unsigned char)(40);
	info_h[4] = (unsigned char)(all->screen_width);
	info_h[5] = (unsigned char)(all->screen_width >> 8);
	info_h[6] = (unsigned char)(all->screen_width >> 16);
	info_h[7] = (unsigned char)(all->screen_width >> 24);
	info_h[8] = (unsigned char)(-all->screen_height);
	info_h[9] = (unsigned char)(-all->screen_height >> 8);
	info_h[10] = (unsigned char)(-all->screen_height >> 16);
	info_h[11] = (unsigned char)(-all->screen_height >> 24);
	info_h[12] = (unsigned char)(1);
	info_h[14] = (unsigned char)(all->image.bpp);
}

void	ft_take_screenshot(t_all *all)
{
	int				i;
	int				block_size;
	int				fd;
	unsigned char	file_h[14];
	unsigned char	info_h[40];

	i = 0;
	fd = open("screenshot.bmp", O_RDWR | O_CREAT, 0755);
	ft_write_bmp_header(all, file_h, info_h);
	write(fd, file_h, 14);
	write(fd, info_h, 40);
	block_size = all->image.bpp / 8 * all->screen_width;
	while (i < all->screen_height)
	{
		write(fd, (&all->image.addr[i * all->image.line_length]), block_size);
		i++;
	}
	close(fd);
	exit(0);
}
