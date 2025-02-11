/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_del_world.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 12:14:25 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/31 18:58:55 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/**
 * Destroy a world.
 */
void del_world(st_world *del)
{
    del_tile(del->tileset);
    del->tileset = NULL;
    del_sprite(del->spriteset);
    del->spriteset = NULL;
    del->ceilling = 0;
    del->floor = 0;
    del->ceilling = 0;

    for (size_t i = 0; del->map[i] != NULL; ++i)
        free(del->map[i]);
    free(del->map);
    
    del->map = NULL;
    del->map_x = 0;
    del->map_y = 0;
    del->abs_x = 0;
    del->abs_y = 0;
    
    free(del);
}
