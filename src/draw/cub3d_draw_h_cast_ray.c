/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_h_cast_ray.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:16:04 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/31 17:50:07 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Ask for a new ray, the calculate it first position and return ths ray.
** Will also make a change in dof value case the player looking straight to    -
** left or right;
*/

static t_ray	create_h_ray(t_actor *p, double ang)
{
	t_ray	ray;
	double	ra_tan;
	int		acc;

	ray = new_ray('H', ang);
	ra_tan = tan(ray.ang);
	acc = 0;
	if (!ray.dirs[UPDN])
		acc = TILESIZE;
	ray.ry = (floor(p->abs_y / TILESIZE) * TILESIZE) + acc;
	ray.rx = p->abs_x + (ray.ry - p->abs_y) / ra_tan;
	ray.yo = TILESIZE;
	if (ray.dirs[UPDN])
		ray.yo *= -1;
	ray.xo = TILESIZE / ra_tan;
	if ((ray.dirs[LTRT] && ray.xo > 0) || (!ray.dirs[LTRT] && ray.xo < 0))
		ray.xo *= -1;
	return (ray);
}

/*
** Cast a single ray that make verifications on horizontal grid of the map.
*/

t_ray	h_cast_ray(t_actor *p, t_world *wrld, float ang)
{
	t_ray	ray;

	ray = create_h_ray(p, ang);
	while ((ray.map_x >= 0 && ray.map_x < wrld->map_x)
		&& (ray.map_y >= 0 && ray.map_y < wrld->map_y))
	{
		ray.map_x = ((int)ray.rx) / TILESIZE;
		ray.map_y = ((int)ray.ry - ray.dirs[UPDN]) / TILESIZE;
		if ((ray.map_y < 0 || ray.map_y >= wrld->map_y)
			|| (ray.map_x < 0 || ray.map_x >= wrld->map_x))
			break ;
		if (wrld->map[ray.map_y][ray.map_x] == '1')
		{
			ray.dist = hypot((ray.rx - p->abs_x), (ray.ry - p->abs_y));
			return (ray);
		}
		ray.rx += ray.xo;
		ray.ry += ray.yo;
	}
	return (ray);
}
