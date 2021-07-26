/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_obj.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:06:01 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/25 23:34:17 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Create a actual sprite instance. The "actual" part is because the existent  -
** s_sprite needs to be renamed, and this s_ac_sprite will keep the "sprite"   -
** in its name, because this refers to the visible sprites.
*/

t_obj new_obj(int wndw_wdt, int wndw_hgt, t_actor *p, t_static_obj obj)
{
	float	d_proj;
	t_obj	new;

	d_proj = (wndw_wdt / 2) - tan(FOV_ANG / 2);
	new.dist = hypot((obj.abs_x - p->abs_x), (obj.abs_y - p->abs_y));
	new.ang = atan2((obj.abs_y - p->abs_y), (obj.abs_x - p->abs_x)) - p->dir;
	new.ang = normalize_angle(new.ang);
	new.ang = fabs(new.ang);
	new.prl_x = tan(new.ang) * d_proj;
	new.wdt = (obj.texture->wdt / new.dist) * d_proj;
	new.hgt = (obj.texture->hgt / new.dist) * d_proj;
	new.org_sy = (wndw_hgt / 2) - (new.hgt / 2);
	new.end_sy = (wndw_hgt / 2) + (new.hgt / 2);
	new.org_sx = wndw_wdt / 2 + new.prl_x;
	new.end_sx = new.org_sx + obj.texture->wdt;
	new.visible = false;
	new.ox = (tan(FOV / 2) * d_proj) + (tan(new.ang - p->dir) * d_proj)
		- (new.hgt / 2);
	return (new);
}
