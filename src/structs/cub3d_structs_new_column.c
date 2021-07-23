/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_column.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 01:29:01 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/23 19:29:35 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Create a new column instance with values already setted.
*/

t_column	new_column(t_wndw *wndw, t_ray *ray, char *tex, float p_dir)
{
	t_column	new;
	
	new.d_proj = (wndw->wdt / 2) / tan(FOV_ANG / 2);
	new.perp_d = ray->dist * cos(ray->ang - p_dir);
	new.hgt = ((TILESIZE / new.perp_d) * new.d_proj);
	new.org_sy = (wndw->hgt / 2) - (new.hgt / 2);
	if (new.org_sy < 0)
		new.org_sy = 0;
	new.end_sy = (wndw->hgt / 2) + (new.hgt / 2);
	if (new.end_sy > wndw->hgt)
		new.end_sy = wndw->hgt;
	new.texture = tex;
	if (ray.id == 'H')
		new.tex_x = ((int)ray->rx % 32);
	else
		new.tex_x = ((int)ray->ry % 32);
	return (new);
}
