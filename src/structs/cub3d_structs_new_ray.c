/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_ray.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:14:26 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/15 20:09:54 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Create a new ray from a start point looking to a certain direction.
** The casting is done by ray_cast function (see cub3d_draw header), here the  -
** values are merely initialized.
*/

t_ray	new_ray(double ang)
{
	t_ray	new;

	new.ang = ang;
	new.dirs[UPDN] = 0;
	new.dirs[RTLT] = 0;
	if (ang > PI)
		new.dirs[UPDN] = 1;
	if (ang < PI / 2 || ang > 3 * PI / 2)
		new.dirs[RTLT] = 1;
	new.yo = 0;
	new.xo = 0;
	new.ry = 0;
	new.rx = 0;
	new.hx = -1;
	new.hy = -1;
	new.vx = -1;
	new.vy = -1;
	new.dist = INT_MAX;
	return (new);
}
