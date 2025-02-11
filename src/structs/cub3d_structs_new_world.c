/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_world.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:17:28 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/31 18:33:17 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/**
 * Count how many sprites are in the world.
 */
static int cnt_sprites(char **map, int map_x, int map_y)
{
    int cnt = 0;

    for (int y = 0; y < map_y; ++y)
    {
        for (int x = 0; x < map_x; ++x)
        {
            if (map[y][x] == '2')
                ++cnt;
        }
    }

    return cnt;
}

/**
 * Create a new t_world using the informed t_cub
 */
st_world *new_world(st_cub *cub, st_wndw *wndw)
{
    st_world *new;

    new = malloc(sizeof(*new));

    if (!new)
        return NULL;

    new->tileset = new_tile(cub->tilesheet, wndw);
    new->spriteset = new_sprite(cub->spritesheet, wndw);
    new->floor = color_picker(cub->c_color);
    new->ceilling = color_picker(cub->f_color);
    new->map = cub->layout;
    new->map_x = cub->map_axis[0];
    new->map_y = cub->map_axis[1];
    new->abs_x = new->map_x * TILESIZE;
    new->abs_y = new->map_y * TILESIZE;
    new->n_sprites = cnt_sprites(new->map, new->map_x, new->map_y);

    return new;
}
