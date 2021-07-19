/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_h_cast_ray.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:16:04 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/19 00:49:42 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Ask for a new ray, the calculate it first position and return ths ray.
** Will also make a change in dof value case the player looking straight to    -
** left or right;
*/

static t_ray	create_h_ray(t_actor *player, double ang)
{
	t_ray	ray;
	float	a_tan;
	int		acc;

	ray = new_ray(ang);
	a_tan = -1 / tan(ray.ang);
	acc = 0;
	if (!ray.dirs[UPDN])
		acc = TILESIZE;
	ray.yo = TILESIZE;
	if (ray.dirs[UPDN])
		ray.yo *= -1;
	ray.xo = -ray.yo * a_tan;
	ray.ry = floor((player->abs_y / TILESIZE) * TILESIZE) + acc;
	ray.rx = (player->abs_y - ray.ry) * a_tan + player->abs_x;
	return (ray);
}

/*
** Cast a single ray horizontally through the map.
*/

t_ray	h_cast_ray(t_actor *player, t_world *wrld, double ang)
{
	t_ray	ray;

	ray = create_h_ray(player, ang);
	if (ray.ang == EAST || ray.ang == WEST)
		return (ray);
	ray.map_x = (int)floor(ray.rx / TILESIZE);
	ray.map_y = (int)floor(ray.ry / TILESIZE);
	while ((ray.map_x >= 0 && ray.map_x < wrld->map_x)
		&& (ray.map_y >= 0 && ray.map_y < wrld->map_y))
	{
		if (wrld->map[ray.map_y][ray.map_x] == '1')
		{
			ray.hx = ray.rx;
			ray.hy = ray.ry;
			ray.color = 0xFF0000;
			return (ray);
		}
		ray.rx += ray.xo;
		ray.ry += ray.yo;
		ray.map_x = (int)floor(ray.rx / TILESIZE);
		ray.map_y = (int)floor(ray.ry / TILESIZE);
	}
	return (ray);
}
