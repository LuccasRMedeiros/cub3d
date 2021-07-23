/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_v_cast_ray.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 21:10:31 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/22 22:55:30 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Ask for a new ray, the calculate it first position and return ths ray.
** Will also make a change in dof value case the player looking straight to    -
** left or right;
*/

static t_ray	create_v_ray(t_actor *p, float ang)
{
	t_ray	ray;
	double	ra_tan;
	int		acc;

	ray = new_ray(ang);
	ray.color = 0x9C0000;
	ra_tan = tan(ray.ang);
	acc = 0;
	if (!ray.dirs[LTRT])
		acc = TILESIZE;
	ray.rx = (floor(p->abs_x / TILESIZE) * TILESIZE) + acc;
	ray.ry = p->abs_y + (ray.rx - p->abs_x) * ra_tan;
	ray.xo = TILESIZE;
	if (ray.dirs[LTRT])
		ray.xo *= -1;
	ray.yo = TILESIZE * ra_tan;
	if ((ray.dirs[UPDN] && ray.yo > 0) || (!ray.dirs[UPDN] && ray.yo < 0))
		ray.yo *= -1;
	return (ray);
}

/*
** Cast a single ray that make verifications on vertical grid of the map.
*/

t_ray	v_cast_ray(t_actor *p, t_world *wrld, float ang)
{
	t_ray	ray;

	ray = create_v_ray(p, ang);
	while ((ray.map_x >= 0 && ray.map_x < wrld->map_x)
		&& (ray.map_y >= 0 && ray.map_y < wrld->map_y))
	{
		ray.map_x = ((int)ray.rx - ray.dirs[LTRT]) / TILESIZE;
		ray.map_y = ((int)ray.ry) / TILESIZE;
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
