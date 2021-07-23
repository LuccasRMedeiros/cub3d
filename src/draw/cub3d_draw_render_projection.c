/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_render_projection.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:03:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/23 20:06:14 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

static void	draw_column(t_screen *f, t_column w_col, int org_sx)
{
	int			sy;

	sy = w_col.org_sy;
	while (sy <= w_col.end_sy)
	{
		pixel_put(f, org_sx, sy, 0xFFFFFF);
		++sy;
	}
	sy = w_col.org_sy;
}

/*
** Draw a column of pixels starting from the given position till the height be -
** complete.
** Receive a t_screen buffer, an array of two integers containing the x and y  -
** reference where the column must start (consider the first index as x and the-
**  second the y), a integer value of height and a serie of color codes to be  -
** pushed to the screen.
*/

void	render_projection(t_screen *f, t_wndw *wndw, t_actor *p)
{
	int			n_ray;
	t_column	w_col;

	n_ray = 0;
	while (n_ray < wndw->wdt)
	{
		w_col = new_column(wndw, &p->rays[n_ray], p->dir);
		if (n_ray >= 790)
			w_col.texture = "any";
		draw_column(f, w_col, n_ray);
		++n_ray;
	}
}
