/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_v_cast_ray.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 21:10:31 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/19 01:07:37 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Ask for a new ray, the calculate it first position and return ths ray.
** Will also make a change in dof value case the player looking straight to    -
** left or right;
*/

static t_ray	create_v_ray(t_actor *player, double ang)
{
	int		acc;
	float	n_tan;
	t_ray	ray;

	acc = TILESIZE;
	ray = new_ray(ang);
	n_tan = -tan(ray.ang);
	ray.xo = TILESIZE;
	if (!ray.dirs[RTLT])
	{
		acc = 0;
		ray.xo *= -1;
	}
	ray.yo = -ray.xo * n_tan;
	ray.rx = floor(player->abs_x / TILESIZE) * TILESIZE + acc;
	ray.ry = (player->abs_x - ray.rx) * n_tan + player->abs_y;
	return (ray);
}

/*
** Cast a single ray vertically through the map.
*/

t_ray	v_cast_ray(t_actor *player, t_world *wrld, double ang)
{
	t_ray	ray;

	ray = create_v_ray(player, ang);
	if (ray.ang == NORTH || ray.ang == SOUTH)
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
			ray.color = 0x0000FF;
			return (ray);
		}
		ray.rx += ray.xo;
		ray.ry += ray.yo;
		ray.map_x = (int)floor(ray.rx / TILESIZE);
		ray.map_y = (int)floor(ray.ry / TILESIZE);
	}
	return (ray);
}
