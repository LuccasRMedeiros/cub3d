/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_list_static_obj.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:37:51 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/25 19:23:35 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** set_actor create a t_actor copy with values filled.
*/

t_static_obj	set_obj(t_world *wrld, int map_x, int map_y)
{
	t_static_obj	new;

	new.id = wrld->spriteset->id;
	new.map_x = map_x;
	new.map_y = map_y;
	new.abs_x = map_x * TILESIZE;
	new.abs_y = map_y * TILESIZE;
	new.texture = wrld->spriteset->sprite;
	return (new);
}

/*
** Look into the world map for sprites, then return a list of them.
*/

t_static_obj	*list_static_obj(t_world *wrld, int n_objs)
{
	t_static_obj	*list;
	int				el;
	int				map_x;
	int				map_y;

	list = (t_static_obj *)ft_calloc(n_objs, sizeof *list);
	el = 0;
	map_x = 0;
	map_y = 0;
	while (map_y < wrld->map_y)
	{
		while (map_x < wrld->map_x)
		{
			if (wrld->map[map_y][map_x] == '2')
			{
				list[el] = set_obj(wrld, map_x, map_y);
				++el;
			}
			++map_x;
		}
		map_x = 0;
		++map_y;
	}
	return (list);
}
