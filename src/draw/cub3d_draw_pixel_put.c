/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_pixel_put.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:49:05 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/10 15:58:17 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Because the mlx_pixel_put function is very slow, it is necessary to create a
** similar function.
** This one keeps the pixels into a buffer and send it to the window.
*/

#include "cub3d_draw.h"

void	pixel_put(t_img *img, int posx, int posy, int color)
{
	char	*dst;

	dst = img->addr + (posy * img->l_len + posx * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
