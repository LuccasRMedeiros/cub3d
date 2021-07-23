/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_update_frame.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:51:56 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/21 23:30:41 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Ask to ray_caster cast rays from the plaer postion then loop through the ray-
**  array and call draw_column to draw each column correspondent to each ray.
*/

void	update_frame(t_wndw *wndw, t_world *wrld, t_actor *p)
{
	t_img	*frame;

	frame = new_img(wndw);
	ray_cast(wrld, p, wndw->wdt);
	draw_background(frame, wndw, wrld);
	render_projection(frame, wndw, p);
	mlx_put_image_to_window(wndw->conn, wndw->wndw, frame->img, 0, 0);
	del_img(frame);
	print_map(wrld, p, wndw->wdt);
}
