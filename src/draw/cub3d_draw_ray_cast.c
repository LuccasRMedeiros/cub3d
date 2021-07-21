/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_ray_cast.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:46:49 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/21 00:46:08 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** ray_cast uses a loop to cast as many rays it need to, due this behavior it  -
** often generates angles "above/below" a complete turn (that would be 2PI or  -
** zero).
** It attempt to regulate the value of angle keeping it more than zero and less-
**  than 2PI (aka EAST).
*/

static float	normalize_angle(float ang)
{
	ang = remainder(ang, EAST);
	if (ang < 0)
		ang += EAST;
	return (ang);
}

/*
** Calculate the distance between two points.
*/

static float	calc_dist(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

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
	if (h_ray.color != -1)
		h_ray.dist = calc_dist(p->abs_x, p->abs_y, h_ray.rx, h_ray.ry);
	if (v_ray.color != -1)
		v_ray.dist = calc_dist(p->abs_x, p->abs_y, v_ray.rx, v_ray.ry);
	if (h_ray.dist < v_ray.dist)
		return (h_ray);
	return (v_ray);
}

/*
** Cast a rays from the player position to the direction it is facing. It will -
** use each casted ray to draw a column of pixels that correponds to the wall  -
** section it finds. 
*/

void	ray_cast(t_world *wrld, t_actor *p)
{
	float	ang;
	size_t	nray;

	ang = p->dir - RDR * 30;
	ang = normalize_angle(ang);
	nray = 0;
	while (nray < 60)
	{
		p->rays[nray] = cast_rays(wrld, p, ang);
		ang = normalize_angle(ang + RDR);
		++nray;
	}
}
