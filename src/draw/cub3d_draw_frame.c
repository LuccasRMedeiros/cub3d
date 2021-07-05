/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_frame.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:35:25 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/04 18:03:03 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Use the player position to draw what is around him.
*/

t_img	*frame(t_world *wrld, t_wndw *wndw)
{
	int		rx;
	int		ry;
	int		ox;
	int		oy;
	t_img	*ret;

	rx = wrld->player_x - ((wndw->wdt / 32) / 2);
	ry = wrld->player_y - ((wndw->hgt / 32) / 2);
	ox = 0;
	oy = 0;
	ret = new_img(wndw);
	while (ry < wrld->map_y && oy * 32 <= wndw->hgt)
	{
		while (rx < wrld->map_x && ox * 32 <= wndw->wdt)
		{
			if (rx >= 0 && ry >= 0)
				if (wrld->map[ry][rx] == '1' || wrld->map[ry][rx] == '2')
					draw_image(ret, &wrld->map[ry][rx], ox * 32, oy * 32);
			++rx;
			++ox;
		}
		rx = wrld->player_x - ((wndw->wdt / 32) / 2);
		ox = 0;
		++ry;
		++oy;
	}
	return (ret);
}
