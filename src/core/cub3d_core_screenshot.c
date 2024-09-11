/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_screenshot.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 20:28:35 by lrocigno          #+#    #+#             */
/*   Updated: 2021/08/01 00:13:44 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_core.h"

/*
** Set the bmp header.
*/

static void	set_bmp_header(t_img *f, t_bmp_h *header)
{
	header->type = 0x4D42;
	header->size = ((f->wdt + f->hgt) * 4) + 54;
	header->reserved = 0x0;
	header->offset = 54;
	header->hdr_sz = 40;
	header->wdt = f->wdt;
	header->hgt = f->hgt;
	header->n_planes = 1;
	header->bpp = 32;
	header->compression = 0;
	header->img_sz_b = (f->wdt + f->hgt) * 4;
	header->res_x = 3200;
	header->res_y = 3200;
	header->n_colors = 0;
	header->i_colors = 0;
}

/*
** Write the initialized header to an bmp file.
*/

static void	write_header(int fd, t_bmp_h header)
{
	write(fd, &header.type, 2);
	write(fd, &header.size, 4);
	write(fd, &header.reserved, 2);
	write(fd, &header.offset, 4);
	write(fd, &header.hdr_sz, 4);
	write(fd, &header.wdt, 4);
	write(fd, &header.hgt, 4);
	write(fd, &header.n_planes, 2);
	write(fd, &header.bpp, 2);
	write(fd, &header.compression, 4);
	write(fd, &header.img_sz_b, 4);
	write(fd, &header.res_x, 4);
	write(fd, &header.res_y, 4);
	write(fd, &header.n_colors, 4);
	write(fd, &header.i_colors, 4);
}

/*
** Draw the screenshot.
*/

static void	draw_bmp(int fd, t_img *f)
{
	unsigned char	*u_addr;
	int 			l;
	int				i;

	u_addr = (unsigned char *)f->addr;
	l = f->hgt;
	while (l >= 0)
	{
		i = l * f->l_len;
		if (write(fd, &u_addr[i], f->l_len) <= 0)
		{
			ft_fprintf(2, "\e[0;31mFailed to write pixels to image\e[0m\n");
			return ;
		}
		--l;
	}
}

/*
** Save a .bpm image from the first rendered frame.
*/

void	screenshot(t_img *f)
{
	t_bmp_h	header;
	char	*file_name;
	int		fd;

	file_name = "./screenshots/sht.bmp";
	fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (!fd)
	{
		ft_fprintf(2, "\e[0;31mCould not save the screen shoot\e[0m\n");
		return ;
	}
	set_bmp_header(f, &header);
	write_header(fd, header);
	draw_bmp(fd, f);
	close(fd);
}
