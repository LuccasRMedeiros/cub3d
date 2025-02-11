/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_render_sprites.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 19:07:12 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/31 17:53:50 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/**
 * Calculate the offset x;
 */
static int calc_ox(st_static_obj spt, int sx)
{
    double step;
    int ox;

    step = ((double)spt.texture->wdt) / ((double)spt.obj.wdt);
    ox = sx - spt.obj.org_sx;
    ox = ((double)ox) * step;

    return ox;
}

/**
 * Caulculate what row of the texture it is looking for.
 */
static int calc_tx_row(st_img *f, st_obj *obj)
{
    int ret;

    ret = 0;

    if (obj->end_sy - obj->org_sy >= f->hgt)
    {
        ret = -obj->org_sy;
        obj->org_sy = 0;
        obj->end_sy = f->hgt;
    }

    return ret;
}

/**
 * Draw a sprite.
 */
static void draw_sprite(st_img *f, st_static_obj spt)
{
    int tx_row, ox, color;

    tx_row = calc_tx_row(f, &spt.obj);

    for (int sy = spt.obj.org_sy; sy <= spt.obj.end_sy; ++sy)
    {
        for (int sx = spt.obj.org_sx; sx < spt.obj.end_sx; ++sx)
        {
            ox = calc_ox(spt, sx);
            color = get_color(spt.texture, spt.obj.hgt, ox, tx_row);

            if (color)
                pixel_put(f, sx, sy, color);

            ++sx;
        }
        ++tx_row;
    }
}

/**
 * Work similar to render projection, but doesn't uses the raycast.
 * Diferently from wall, sprites doesn't get distorted depending on the player 
 * angle, for that reason there are no need for ray information to project the 
 * sprites on the screen.
 */
void render_sprites(st_img *f, st_static_obj *spt_lst, int n_spts)
{
    for (int si = 0; si < n_spts; ++si)
    {
        if (spt_lst[si].obj.visible)
            draw_sprite(f, spt_lst[si]);
    }
}
