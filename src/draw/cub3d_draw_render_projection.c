/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_render_projection.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:03:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/22 11:44:36 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

static void	draw_column(t_img *f, t_column w_col, int org_sx)
{
	int			sy;

	sy = w_col.org_sy;
	while (sy <= w_col.end_sy)
	{
		pixel_put(f, org_sx, sy, w_col.color);
		++sy;
	}
	sy = w_col.org_sy;
}

/*
** Draw a column of pixels starting from the given position till the height be -
** complete.
** Receive a t_img buffer, an array of two integers containing the x and y     -
** reference where the column must start (consider the first index as x and the-
**  second the y), a integer value of height and a serie of color codes to be  -
** pushed to the screen.
*/

void	render_projection(t_img *f, t_wndw *wndw, t_actor *p)
{
	int			n_ray;
	t_column	w_col;

	n_ray = 0;
	w_col = new_column(wndw, &p->rays[n_ray], p->dir);
	while (n_ray < wndw->wdt)
	{
		draw_column(f, w_col, n_ray);
		w_col = new_column(wndw, &p->rays[n_ray], p->dir);
		++n_ray;
	}
}
