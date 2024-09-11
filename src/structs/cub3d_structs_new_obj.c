/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_obj.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:06:01 by lrocigno          #+#    #+#             */
/*   Updated: 2024/09/11 12:32:59 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/**
 * Return which value is greater
 *
 * NOTE: This function was added after i quited 42, it might not conform to the
 * norm.
 */
static int get_greater(int a, int b)
{
    return a > b ? a : b;
}

/*
** Find the begginings and the ends.
*/

static void	sage(t_wndw *wndw, t_obj *obj, t_actor *p)
{
	int	org_sx;
	int	end_sx;

	org_sx = (wndw->wdt / 2) + obj->p_rl_x;
	end_sx = -get_greater((org_sx + obj->wdt) * -1, -wndw->wdt);
	org_sx = get_greater(org_sx, 0);
	while (p->rays[org_sx].dist <= obj->dist && org_sx < end_sx)
		++org_sx;
	while (p->rays[end_sx].dist <= obj->dist && end_sx > org_sx)
		--end_sx;
	obj->org_sx = org_sx;
	obj->end_sx = end_sx;
	if (org_sx >= end_sx)
		obj->visible = false;
}

/*
** The player relative angle is the product of the difference between the      -
** player direction minus the arch tangent between the distance of the player  -
** and such sprite. As it is a difence, the normalization is diferent.
** So when the "player relative angle" is greater than PI (or 180°), we        -
** subtract it by 2PI , or if it is less than negative PI, we add 2PI.
** After all the operation we ask for the absolute value of this operation and -
** return it.
*/

static float	get_p_rl_ang(t_static_obj obj, t_actor *p)
{
	float	ret;

	ret = p->dir - atan2((obj.abs_y - p->abs_y), (obj.abs_x - p->abs_x));
	if (ret > PI)
		ret -= TPI;
	if (ret < -PI)
		ret += TPI;
	ret = fabs(ret);
	return (ret);
}

/*
** Create a t_obj instance.
** Each t_obj instance carries information that is updated in real time about
** sprites.
*/

t_obj	new_obj(t_wndw *wndw, t_actor *p, t_static_obj obj)
{
	t_obj	new;

	new.p_rl_ang = get_p_rl_ang(obj, p);
	if (new.p_rl_ang < ((FOV_ANG / 2) + 0.2))
	{
		new.visible = true;
		new.dist = hypot(obj.abs_x - p->abs_x, obj.abs_y - p->abs_y);
		new.s_rl_ang = atan2(obj.abs_y - p->abs_y, obj.abs_x - p->abs_x);
		new.s_rl_ang -= p->dir;
		new.p_rl_x = (tan(new.s_rl_ang) * p->d_proj) - TILESIZE;
		new.hgt = (TILESIZE / new.dist) * p->d_proj;
		new.wdt = new.hgt;
		new.org_sy = (wndw->hgt / 2) - (new.hgt / 2);
		new.end_sy = new.org_sy + new.hgt;
		sage(wndw, &new, p);
	}
	else
	{
		new.visible = false;
		new.dist = INT_MAX;
	}
	return (new);
}
