/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_draw_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:03:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/04 19:13:48 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Because the mlx_pixel_put function is very slow, it is necessary to create a
** similar function.
** This one keeps the pixels into a buffer and send it to the window.
*/

void	pixel_put(t_img *img, int posx, int posy, int color)
{
	char	*dst;

	dst = img->addr + (posy * img->l_len + posx * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

/*
** Uses pixel_put to draw a image on the screen.
*/

void	draw_image(t_img *img, char *el, int org_x, int org_y)
{
	size_t	col;
	size_t	row;
	int		color;

	col = 0;
	row = 0;
	color = 0;
	if (*el == '1')
		color = 0xFF0000;
	else if (*el == '2')
		color = 0x00FF00;
	while (row < 32)
	{
		while (col < 32)
		{
			pixel_put(img, row + org_x, col + org_y, color);
			++col;
		}
		col = 0;
		++row;
	}
}
