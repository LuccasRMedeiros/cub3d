/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_get_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 22:33:44 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/31 17:47:34 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Get the pixel on the texture. To decide what pixel it is looking for, it    -
** needs the wall projected height and "distribute" to the texture height,     -
** taking in consideration of course what "line" of the column it is drawing.
*/

int	get_color(t_img *texture, int hgt, int ox, int tx_row)
{
	int	oy;
	int	color;

	oy = tx_row * texture->hgt / (double)hgt;
	color = texture->addr[oy * texture->wdt + ox];
	return (color);
}
