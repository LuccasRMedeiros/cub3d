/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_column.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 01:29:01 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/25 03:50:01 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Select what wall texture it will use.
*/

static t_img	*select_texture(t_world *wrld, t_ray *ray)
{
	if (ray->id == 'H')
	{
		if (ray->dirs[UPDN])
			return (wrld->tileset->wall_so);
		else
			return (wrld->tileset->wall_no);
	}
	else if (ray->id == 'V')
	{
		if (ray->dirs[LTRT])
			return (wrld->tileset->wall_ea);
		else
			return (wrld->tileset->wall_we);
	}
	return (NULL);
}

/*
** Calcule the column where to start drawing the texture.
*/

static int	calcule_ox(t_img *texture, t_ray *ray)
{
	double	step;
	int		ox;

	step = ((double)texture->wdt / (double)TILESIZE);
	ox = 0;
	if (ray->id == 'H')
		ox = (int)ray->rx % TILESIZE;
	else if (ray->id == 'V')
		ox = (int)ray->ry % TILESIZE;
	ox = (double)ox * step;
	return (ox + 8);
}

/*
** Create a new column instance with values already setted.
*/

t_column	*new_column(t_wndw *wndw, t_world *wrld, t_ray *ray, float p_dir)
{
	t_column	*new;
	
	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->d_proj = (wndw->wdt / 2) / tan(FOV_ANG / 2);
	new->perp_d = ray->dist * cos(ray->ang - p_dir);
	new->hgt = ((TILESIZE / new->perp_d) * new->d_proj);
	new->org_sy = (wndw->hgt / 2) - (new->hgt / 2);
	if (new->org_sy < 0)
		new->org_sy = 0;
	new->end_sy = (wndw->hgt / 2) + (new->hgt / 2);
	if (new->end_sy > wndw->hgt)
		new->end_sy = wndw->hgt;
	new->texture = select_texture(wrld, ray);
	new->ox = calcule_ox(new->texture, ray);
	return (new);
}
