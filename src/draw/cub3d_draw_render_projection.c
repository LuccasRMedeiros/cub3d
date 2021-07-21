/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_render_projection.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:03:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/21 02:22:08 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

static void	draw_column(t_img *f, t_column w_col, int org_sx)
{
	int			n_col;
	int			sx;
	int			sy;

	n_col = 0;
	sx = org_sx;
	sy = w_col.org_sy;
	while (n_col < 13)
	{
		while (sy <= w_col.end_sy)
		{
			pixel_put(f, sx, sy, w_col.color);
			++sy;
		}
		sy = w_col.org_sy;
		++sx;
		++n_col;
	}
}

/*
** Draw a column of pixels starting from the given position till the height be -
** complete.
** Receive a t_img buffer, an array of two integers containing the x and y     -
** reference where the column must start (consider the first index as x and the-
**  second the y), a integer value of height and a serie of color codes to be  -
** pushed to the screen.
*/

void	render_projection(t_wndw *wndw, t_actor *p)
{
	size_t		n_ray;
	t_img		*f;
	t_column	w_col;

	n_ray = 0;
	f = new_img(wndw);
	w_col = new_column(wndw, &p->rays[n_ray], p->dir);
	while (n_ray < 60)
	{
		draw_column(f, w_col, n_ray * 13);
		w_col = new_column(wndw, &p->rays[n_ray], p->dir);
		++n_ray;
	}
	mlx_put_image_to_window(wndw->conn, wndw->wndw, f->img, 0, 0);
	del_img(f);
}
