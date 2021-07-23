/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_ray_cast.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:46:49 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/23 00:02:25 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Cast two rays, one horizontally and one vertically, then compare which one  -
** is the shortest returning the winner.
** The travelled distance is calculated by using the hypot funciontion.
*/

static t_ray	cast_rays(t_world *wrld, t_actor *p, double ang)
{
	t_ray	h_ray;
	t_ray	v_ray;

	h_ray = h_cast_ray(p, wrld, ang);
	v_ray = v_cast_ray(p, wrld, ang);
	if ((h_ray.dist < v_ray.dist)
		|| (h_ray.dist == v_ray.dist && h_ray.dirs[UPDN]))
		return (h_ray);
	return (v_ray);
}

/*
** Cast a rays from the player position to the direction it is facing. It will -
** use each casted ray to draw a column of pixels that correponds to the wall  -
** section it finds. 
*/

void	ray_cast(t_world *wrld, t_actor *p, int n_rays)
{
	float	dist_proj;
	float	ang;
	int		ray;
	t_ray	aray[n_rays];

	dist_proj = ((n_rays / 2) / tan(FOV_ANG / 2));
	ang = 0;
	ray = 0;
	while (ray < n_rays)
	{
		ang = normalize_angle(p->dir + atan((ray - n_rays / 2) / dist_proj));
		aray[ray] = cast_rays(wrld, p, ang);
		++ray;
	}
	p->rays = aray;
}
