/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_render_sprites.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 19:07:12 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/25 23:39:11 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Draw a sprite.
*/

static void	draw_sprite(t_img *f, t_static_obj spt)
{
	int	tx_row;
	int	sy;
	int	color;

	tx_row = 0;
	if (spt.obj.end_sy - spt.obj.org_sy >= f->hgt)
	{
		tx_row += -spt.obj.org_sy;
		spt.obj.org_sy = 0;
		spt.obj.org_sx = f->hgt;
	}
	sy = spt.obj.org_sy;
	while (sy <= spt.obj.end_sy)
	{
		color = get_color(spt.texture, spt.texture->hgt, spt.obj.ox, tx_row);
		pixel_put(f, spt.obj.org_sx, sy, color);
		++sy;
		++tx_row;
	}
}

/*
** Bubble sort the sprites by its distance from the player.
*/

static void	sort_sprites(t_static_obj *sprite_list, int nspt)
{
	t_static_obj	temp;
	int				spti;

	spti = 0;
	while (spti < nspt - 1)
	{
		if (sprite_list[spti].obj.dist < sprite_list[spti + 1].obj.dist)
		{
			temp = sprite_list[spti];
			sprite_list[spti] = sprite_list[spti + 1];
			sprite_list[spti + 1] = temp;
		}
		++spti;
	}
}

/*
** Work similar to render projection, but doesn't uses the raycast.
** Diferently from wall, sprites doesn't get distorted depending on the player -
** angle, for that reason there are no need for ray information to project the -
** sprites on the screen.
*/

void    render_sprite(t_img *f, t_static_obj *sprite_list, t_actor *p, int nspt)
{
	int	si;

	si = 0;
	while (si < nspt)
	{
		sprite_list[si].obj = new_obj(f->wdt, f->hgt, p, sprite_list[si]);
		if (sprite_list[si].obj.ang < (FOV / 2) + 0.2)
			sprite_list[si].obj.visible = true;
		++si;
	}
	sort_sprites(sprite_list, nspt);
	si = 0;
	while (si < nspt)
	{
		if (sprite_list[si].obj.visible)
			draw_sprite(f, sprite_list[si]);
		++si;
	}
}