/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_draw_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:35:25 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/03 19:57:26 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Draw the map on screen.
** It look for the player position and draw everything that is around.
*/

void	draw_map(t_world *wrld, t_wndw *wndw)
{
	int	rx;
	int	ry;
	int	ox;
	int	oy;

	rx = wrld->player_x - ((wndw->screen->wdt / 32) / 2);
	ry = wrld->player_y - ((wndw->screen->hgt / 32) / 2);
	ox = 0;
	oy = 0;
	draw_player(wndw, wrld);
	while (ry < wrld->map_y && oy * 32 <= wndw->screen->hgt)
	{
		while (rx < wrld->map_x && ox * 32 <= wndw->screen->wdt)
		{
			if (rx >= 0 && ry >= 0)
				if (wrld->map[ry][rx] == '1' || wrld->map[ry][rx] == '2')
					draw_image(wndw, &wrld->map[ry][rx], ox * 32, oy * 32);
			++rx;
			++ox;
		}
		rx = wrld->player_x - ((wndw->screen->wdt / 32) / 2);
		ox = 0;
		++ry;
		++oy;
	}
}
