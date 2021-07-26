/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_get_obj_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:23:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/25 23:43:33 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_core.h"

/*
** Get the actors (sprites and player) on the map and create a list of them.
*/

t_static_obj *get_obj_list(t_world *wrld, int *nspt)
{
	int		cnt_obj;
	int		map_x;
	int		map_y;

	cnt_obj = 0;
	map_x = 0;
	map_y = 0;
	while (map_y < wrld->map_y)
	{
		while (map_x < wrld->map_x)
		{
			if (wrld->map[map_y][map_x] == '2')
				++cnt_obj;
			++map_x;
		}
		map_x = 0;
		++map_y;
	}
	*nspt = cnt_obj;
	return(list_static_obj(wrld, cnt_obj));
}
