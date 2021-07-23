/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_pixel_put.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:32:18 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/23 19:37:11 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Because the mlx_pixel_put function is very slow, it is necessary to create a-
**  similar function.
** In this version, the pixels are stored into a buffer before been pushed to  -
** the screen.
** Receives a t_screen containing important informations about the frame that  -
** is being drawn, posx refers to the screen column, posy, the screen row and  -
** color is a shifted integer that corresponds to a RGB color.
*/

void	pixel_put(t_screen *f, int posx, int posy, int color)
{
	char	*dst;

	dst = f->addr + (posy * f->l_len + posx * (f->bpp / 8));
	*(unsigned int *)dst = color;
}
