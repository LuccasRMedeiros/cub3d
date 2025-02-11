/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_list_static_obj.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:37:51 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/31 18:09:28 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/**
 * set_actor create a t_actor copy with values filled.
 */
static st_static_obj get_static_obj(st_world *wrld, int map_x, int map_y)
{
    st_static_obj new;

    new.id = wrld->spriteset->id;
    new.map_x = map_x;
    new.map_y = map_y;
    new.abs_x = (map_x * TILESIZE) + (TILESIZE / 2);
    new.abs_y = (map_y * TILESIZE) + (TILESIZE / 2);
    new.texture = wrld->spriteset->sprite;

    return (new);
}

/**
 * Look for the counted sprites to get its map x and map y positions and its   -
 * absolutes positions.
 */
st_static_obj *list_static_obj(st_world *wrld)
{
    st_static_obj *ret_list;
    int el, map_x, map_y;

    ret_list = calloc(wrld->n_sprites, sizeof(*ret_list));
    el = 0;

    for (int map_y = 0; map_y < wrld->map_y && el < wrld->n_sprites; ++map_y)
    {
        for (int map_x = 0; wrld->map_x && el < wrld->n_sprites; ++map_x)
        {
            if (wrld->map[map_y][map_x] == '2')
            {
                ret_list[el] = get_static_obj(wrld, map_x, map_y);
                ++el;
            }
        }
    }

    return (ret_list);
}
