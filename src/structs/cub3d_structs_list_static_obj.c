/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_list_static_obj.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:37:51 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/30 18:06:14 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** set_actor create a t_actor copy with values filled.
*/

static t_static_obj	get_static_obj(t_world *wrld, int map_x, int map_y)
{
	t_static_obj	new;

	new.id = wrld->spriteset->id;
	new.map_x = map_x;
	new.map_y = map_y;
	new.abs_x = (map_x * TILESIZE) + (TILESIZE / 2);
	new.abs_y = (map_y * TILESIZE) + (TILESIZE / 2);
	new.texture = wrld->spriteset->sprite;
	return (new);
}

/*
** Look for the counted sprites to get its map x and map y positions and its   -
** absolutes positions.
*/

t_static_obj	*list_static_obj(t_world *wrld)
{
	t_static_obj	*ret_list;
	int				el;
	int				map_x;
	int				map_y;
	
	ret_list = ft_calloc(wrld->n_sprites, sizeof *ret_list);
	el = 0;
	map_x = 0;
	map_y = 0;
	while (map_y < wrld->map_y && el < wrld->n_sprites)
	{
		while (map_x < wrld->map_x && el < wrld->n_sprites)
		{
			if (wrld->map[map_y][map_x] == '2')
			{
				ret_list[el] = get_static_obj(wrld, map_x, map_y);
				++el;
			}
			++map_x;
		}
		map_x = 0;
		++map_y;
	}
	return (ret_list);
}
