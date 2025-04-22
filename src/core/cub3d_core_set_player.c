/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_set_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:58:53 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/16 16:57:45 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_core.h"

#include <string.h>

/**
 * Search for the player.
 * Only succed if there are one (and not more) player in the map.
 */
void set_player(st_cub *cub)
{
    // TODO: Make the validation more straigthforward to remove this part
    if (!validate_player_pos(cub))
    {
        cub->status = -1;
        return ;
    }
    for (int map_y = 0; map_y < cub->map_axis[AXIS_Y]; ++map_y)
    {
        for (int map_x = 0; map_x < cub->map_axis[AXIS_X]; ++map_x)
        {
            if (strchr(PLAYER, cub->layout[map_y][map_x]) != NULL)
            {
                cub->player_pos[AXIS_X] = map_x;
                cub->player_pos[AXIS_Y] = map_y;
            }
        }
    }
}
