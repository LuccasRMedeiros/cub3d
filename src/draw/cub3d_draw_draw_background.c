/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_draw_background.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 11:26:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/25 12:26:31 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/**
 * Draw the images of ceilling and floor.
 */
void draw_background(st_img *f, st_wndw *wndw, st_world *wrld)
{
    for (int sy = 0; sy < wndw->hgt; ++sy)
    {
        for (int sx = 0; sx < wndw->wdt; ++sx)
        {
            if (sy > wndw->hgt / 2)
                pixel_put(f, sx, sy, wrld->ceilling);
            else
                pixel_put(f, sx, sy, wrld->floor);
        }
    }   
}
