/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_draw_background.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 11:26:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/24 21:09:30 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Draw the images of ceilling and floor.
*/

void	draw_background(t_img *f, t_wndw *wndw, t_world *wrld)
{
	int	sx;
	int	sy;

	sx = 0;
	sy = 0;
	while (sy < wndw->hgt)
	{
		while (sx < wndw->wdt)
		{
			if (sy < wndw->hgt / 2)
				pixel_put(f, sx, sy, wrld->ceilling);
			else
				pixel_put(f, sx, sy, wrld->floor);
			++sx;
		}
		sx = 0;
		++sy;
	}	
}
