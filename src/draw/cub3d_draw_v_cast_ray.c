/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_v_cast_ray.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 21:10:31 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/15 19:11:24 by lrocigno         ###   ########.fr       */
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
	t_ray	ray;

	acc = 0;
	if (!ray.dirs[RTLT])
		acc = TILESIZE;
	ray = new_ray(ang);
	ray.xo = TILESIZE;
	if (ray.dirs[RTLT])
		ray.xo *= -1;
	ray.yo = ray.xo * tan(ang);
	ray.rx = floor(player->abs_x / TILESIZE) * TILESIZE + acc;
	ray.ry = player->abs_y + (ray.rx - player->abs_x) * tan(ang);
	if ((!ray.dirs[UPDN] && ray.yo > 0) || (ray.dirs[UPDN] && ray.yo < 0))
		ray.ry = -ray.ry;
	return (ray);
}

/*
** Cast a single ray horizontally through the map.
*/

t_ray	v_cast_ray(t_actor *player, t_world *wrld, double ang)
{
	t_ray	ray;
	int		map_x;
	int		map_y;

	ray = create_v_ray(player, ang);
	map_x = (int)floor(ray.rx / TILESIZE);
	map_y = (int)floor(ray.ry / TILESIZE);
	while ((map_x >= 0 && map_x <= wrld->map_x)
		&& (map_y >= 0 && map_y <= wrld->map_y))
	{
		if (wrld->map[map_y][map_x] == '1')
		{
			ray.vx = ray.rx;
			ray.vy = ray.ry;
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
