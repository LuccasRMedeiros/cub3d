/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_render_sprites.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 19:07:12 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/30 17:45:43 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Caulculate what row of the texture it is looking for.
*/

static int	calc_tx_row(t_img *f, t_obj *obj)
{
	int	ret;

	ret = 0;
	if (obj->end_sy - obj->org_sy >= f->hgt)
	{
		ret = -obj->org_sy;
		obj->org_sy = 0;
		obj->end_sy = f->hgt;
	}
	return (ret);
}

/*
** Draw a sprite.
*/

static void	draw_sprite(t_img *f, t_static_obj spt)
{
	int	tx_row;
	int	sy;
    int sx;
    int ox;
	int	color;

	tx_row = calc_tx_row(f, &spt.obj);
	sy = spt.obj.org_sy;
	while (sy <= spt.obj.end_sy)
	{
        sx = spt.obj.org_sx;
		while (sx < spt.obj.end_sx)
		{
            ox = sx * (double)spt.texture->wdt / (double)spt.obj.wdt;
			// color = get_color(spt.texture, spt.obj.hgt, ox, tx_row);
			color = 0x00FF00;
            if (color)
			    pixel_put(f, sx, sy, color);
			++sx;
		}
		++sy;
		++tx_row;
	}
}

/*
** Work similar to render projection, but doesn't uses the raycast.
** Diferently from wall, sprites doesn't get distorted depending on the player -
** angle, for that reason there are no need for ray information to project the -
** sprites on the screen.
*/

void    render_sprites(t_img *f, t_static_obj *spt_lst, int n_spts)
{
	int	si;

	si = 0;
	while (si < n_spts)
	{
		if (spt_lst[si].obj.visible)
			draw_sprite(f, spt_lst[si]);
		++si;
	}
}
