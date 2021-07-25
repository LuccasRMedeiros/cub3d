/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_render_projection.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:03:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/25 03:49:16 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

static int	get_color(t_wndw *wndw, t_column *w_col, int sy)
{
	int	d_top;
	int	oy;

	d_top = sy + (w_col->hgt / 2) - (wndw->hgt / 2);
	oy = d_top * ((float)w_col->texture->hgt / w_col->hgt);
	return (*(unsigned int *)w_col->texture->addr + (oy + w_col->texture->l_len
		+ w_col->ox * (w_col->texture->bpp / 8)));
}

static void	draw_column(t_img *f, t_wndw *wndw, t_column *w_col, int org_sx)
{
	int	sy;
	int	color;

	sy = w_col->org_sy;
	while (sy <= w_col->end_sy)
	{
		color = get_color(wndw, w_col, sy);
		pixel_put(f, org_sx, sy, color);
		++sy;
	}
	sy = w_col->org_sy;
}

/*
** Draw a column of pixels starting from the given position till the height be -
** complete.
** Receive a t_img buffer, an array of two integers containing the x and y     -
** reference where the column must start (consider the first index as x and the-
**  second the y), a integer value of height and a serie of color codes to be  -
** pushed to the screen.
*/

void	render_projection(t_img *f, t_world *wrld, t_wndw *wndw, t_actor *p)
{
	int			n_ray;
	t_column	*w_col;

	n_ray = 0;
	while (n_ray < wndw->wdt)
	{
		w_col = new_column(wndw, wrld, &p->rays[n_ray], p->dir);
		draw_column(f, wndw, w_col, n_ray);
		del_column(w_col);
		++n_ray;
	}
}
