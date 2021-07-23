/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_draw_background.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 11:26:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/21 13:54:35 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Draw the entire background using the colors of ceilling and floor.
*/

void	draw_background(t_img *bg, t_wndw *wndw, t_world *wrld)
{
	int	sx;
	int	sy;
	int	color;

	sx = 0;
	sy = 0;
	color = wrld->ceilling;
	while (sy < wndw->hgt)
	{
		if (sy > wndw->hgt / 2)
			color = wrld->floor;
		while (sx < wndw->wdt)
		{
			pixel_put(bg, sx, sy, color);
			++sx;
		}
		sx = 0;
		++sy;
	}
}
