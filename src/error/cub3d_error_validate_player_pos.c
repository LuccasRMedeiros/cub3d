/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error_validate_player_pos.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:34:40 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/23 19:21:09 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_error.h"

#include <string.h>

/**
 * If necessary, send an apropriate error message.
 * Return false or true.
 */
static int send_msg(int p_cnt)
{
    if (p_cnt < 1)
    {
        error_msg("No player present in the given map", "Map");

        return 0;
    }
    else if (p_cnt > 1)
    {
        error_msg("More than one player present in the map", "Map");

        return 0;
    }
    else
        return 1;
}

/*
** Verify if there are only one player on map layout.
*/

int validate_player_pos(st_cub *cub)
{
    int p_cnt;

    p_cnt = 0;

    for (size_t row = 0; cub->layout[row]; ++row)
    {
        for (size_t col = 0; cub->layout[row][col]; ++col)
        {
            if (strpbrk(PLAYER, cub->layout[row]))
                ++p_cnt;
        }
    }

    return send_msg(p_cnt);
}
