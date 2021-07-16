/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_ray_cast.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:46:49 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/15 18:43:05 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** ray_cast uses a loop to cast as many rays it need to, due this behavior it  -
** often generates angles "above/below" a complete turn (that would be 2PI or  -
** zero).
** It attempt to regulate the value of angle keeping it more than zero and less-
**  than 2PI.
*/

static double	normalize_angle(double ang)
{
	ang = remainder(ang, TPI);
	if (ang < TPI)
		ang += TPI;
	return (ang);
}

/*
** Cast two rays, one horizontally and one vertically, then compare which one  -
** is the shortest returning the winner.
** The travelled distance is calculated by using the hypot funciontion.
*/

static t_ray	cast_ray(t_world *wrld, t_actor *player, double ang)
{
	t_ray	h_ray;
	t_ray	v_ray;

	h_ray = h_cast_ray(player, wrld, ang);
	v_ray = v_cast_ray(player, wrld, ang);
	if (h_ray.hx && h_ray.hy)
		h_ray.dist = hypot(player->abs_x - h_ray.hx, player->abs_y - h_ray.hy);
	if (v_ray.hx && v_ray.hy)
		v_ray.dist = hypot(player->abs_x - h_ray.hx, player->abs_y - h_ray.hy);
	if (h_ray.dist > v_ray.dist)
		return (h_ray);
	return (v_ray);
}

/*
** Cast a rays from the player position to the direction it is facing. It will -
** use each casted ray to draw a column of pixels that correponds to the wall  -
** section it finds.
*/

void	ray_cast(t_world *wrld, t_actor *player)
{
	double	ang;
	size_t	nray;
	t_ray	rays[60];

	ang = player->dir - RDR * 30;
	ang = normalize_angle(ang);
	nray = 0;
	while (nray < 60)
	{
		rays[nray] = cast_ray(wrld, player, ang);
		ang = normalize_angle(ang + RDR);
	}
}
