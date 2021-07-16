/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_h_cast_ray.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 19:16:04 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/15 19:11:25 by lrocigno         ###   ########.fr       */
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
	int		acc;
	t_ray	ray;

	acc = 0;
	if (!ray.dirs[UPDN])
		acc = TILESIZE;
	ray = new_ray(ang);
	ray.yo = TILESIZE;
	if (ray.dirs[UPDN])
		ray.yo *= -1;
	ray.xo = ray.yo / tan(ang);
	ray.ry = floor(player->abs_y / TILESIZE) * TILESIZE + acc;
	ray.rx = player->abs_x + (ray.ry - player->abs_y) / tan(ang);
	if ((!ray.dirs[RTLT] && ray.xo > 0) || (ray.dirs[RTLT] && ray.xo < 0))
		ray.rx = -ray.rx;
	return (ray);
}

/*
** Cast a single ray horizontally through the map.
** When the ray does not find a horizontal wall, return null.
*/

t_ray	h_cast_ray(t_actor *player, t_world *wrld, double ang)
{
	t_ray	ray;
	int		map_x;
	int		map_y;

	ray = create_h_ray(player, ang);
	map_x = (int)floor(ray.rx / TILESIZE);
	map_y = (int)floor(ray.ry / TILESIZE);
	while ((map_x >= 0 && map_x <= wrld->map_x)
		&& (map_y >= 0 && map_y <= wrld->map_y))
	{
		if (wrld->map[map_y][map_x] == '1')
		{
			ray.hx = ray.rx;
			ray.hy = ray.ry;
			return (ray);
		}
		else
		{
			ray.rx += ray.xo;
			ray.ry += ray.yo;
			map_x = (int)floor(ray.rx / TILESIZE);
			map_y = (int)floor(ray.ry / TILESIZE);
		}
	}
	return (ray);
}
