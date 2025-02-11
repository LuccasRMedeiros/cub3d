/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_render_projection.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:03:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/28 17:16:28 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/**
 * Draw the wall texture accordingly to the wall height and angle from the     
 * player.
 */
static void draw_column(st_img *f, st_column *w_col, int org_sx)
{
    int tx_row;
    int sy;
    int color;

    tx_row = 0;

    if ((w_col->end_sy - w_col->org_sy) >= f->hgt)
    {
        tx_row += -w_col->org_sy;
        w_col->org_sy = 0;
        w_col->end_sy = f->hgt;
    }

    for (sy = w_col->org_sy; sy <= w_col->end_sy; ++sy)
    {
        color = get_color(w_col->texture, w_col->hgt, w_col->ox, tx_row);
        pixel_put(f, org_sx, sy, color);
        ++tx_row;
    }

    sy = w_col->org_sy;
}

/**
 * Draw a column of pixels starting from the given position till the height be 
 * complete.
 * Receive a t_img buffer, an array of two integers containing the x and y     
 * reference where the column must start (consider the first index as x and the
 * second the y), a integer value of height and a serie of color codes to be  
 * pushed to the screen.
 */
void render_projection(st_img *f, st_world *wrld, st_wndw *wndw, st_actor *p)
{
    st_column *w_col;

    for (int n_ray = 0; n_ray < wndw->wdt; ++n_ray)
    {
        w_col = new_column(wndw, wrld, &p->rays[n_ray], p->dir);
        draw_column(f, w_col, n_ray);
        del_column(w_col);
    }
}
