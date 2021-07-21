/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_render_projection.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:03:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/21 01:04:35 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

static void	draw_column(t_img *f, int org_y, int org_x, int h_wall, int l_col, int color)
{
	int	wdt;
	int	hgt;
	int	act_y;

	wdt = 0;
	hgt = 0;
	act_y = org_y;
	while (wdt <= l_col)
	{
		while (hgt <= h_wall)
		{
			pixel_put(f, org_x, act_y, color);
			++hgt;
			++act_y;
		}
		++wdt;
		++org_x;
		act_y = org_y;
		hgt = 0;
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

void	render_projection(t_img *f, t_wndw *wndw, t_world *wrld, t_actor *p)
{
	size_t	n_ray;
	int		l_col;
	int		h_wall;
	int		org_y;
	int		org_x;

	ray_cast(wrld, p);
	n_ray = 0;
	l_col = wndw->wdt / 60;
	h_wall = 0;
	org_y = 0;
	org_x = 0;
	while (n_ray < 60)
	{
		h_wall = (TILESIZE * wndw->hgt) / p->rays[n_ray].dist;
		if (h_wall > wndw->hgt)
			h_wall = wndw->hgt;
		org_y = wndw->hgt / 2 + h_wall / 2;
		draw_column(f, org_y, org_x, h_wall, l_col, p->rays[n_ray].color);
		++n_ray;
		org_x += l_col;
	}
}
