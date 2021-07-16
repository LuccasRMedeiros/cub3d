/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_update_frame.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:51:56 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/10 19:38:51 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Use the plryer position to draw what is around him.
*/

//static void	next_frame(t_img *f, t_world *wrld, t_actor *p, t_wndw *wndw)
//{
//	int	rx;
//	int	ry;
//	int	ox;
//	int	oy;
//
//	rx = p->map_x - ((wndw->wdt / 32) / 2);
//	ry = p->map_y - ((wndw->hgt / 32) / 2);
//	ox = 0;
//	oy = 0;
//	while (ry < wrld->map_y && oy * 32 < wndw->hgt)
//	{
//		while (rx < wrld->map_x && ox * 32 < wndw->wdt)
//		{
//			if (rx >= 0 && ry >= 0)
//				if (wrld->map[ry][rx] != ' ' && wrld->map[ry][rx] != '0')
//					draw_image(f, wrld->map[ry][rx], ox * 32, oy * 32);
//			++rx;
//			++ox;
//		}
//		rx = wrld->plryer_x - ((wndw->wdt / 32) / 2);
//		ox = 0;
//		++ry;
//		++oy;
//	}
//	draw_image(f, 'P', wndw->wdt / 2 - 16, wndw->hgt / 2 - 12);
//}

/*
** Update the window by replacing the image that is on the screen.
*/

//void	update_frame(t_wndw *wndw, t_world *wrld)
//{
//	t_img	*frame;
//	
//	frame = new_img(wndw);
//	//next_frame(frame, wrld, wndw);
//	mlx_put_image_to_window(wndw->conn, wndw->wndw, frame->img, 0, 0);
//	del_img(frame);
//}