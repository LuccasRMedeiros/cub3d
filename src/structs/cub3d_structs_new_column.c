/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_column.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 01:29:01 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/21 02:24:15 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Create a new column instance with values already setted.
*/

t_column	new_column(const t_wndw *wndw, const t_ray *ray, float dir)
{
	t_column	new;
	
	new.d_proj = (wndw->wdt / 2) / tan(FOV_ANG / 2);
	new.perp_d = ray->dist * cos(ray->ang - dir);
	new.hgt = (int)((TILESIZE / new.perp_d) * new.d_proj);
	new.wdt = wndw->wdt / 60;
	new.org_sy = (wndw->hgt / 2) - (new.hgt / 2);
	new.end_sy = (wndw->hgt / 2) + (new.hgt / 2);
	new.color = ray->color;
	return (new);
}
