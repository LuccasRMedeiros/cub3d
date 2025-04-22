/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error_validate_map.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:46:55 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/31 17:55:50 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_error.h"
#include "libmaker_types.h"

#include <string.h>
#include <stdio.h>

/**
 * Check if there are walls surrounding the map
 */
static st_ipoint *look_arround(st_cub *cub)
{

    char **layout = cub->layout;
    unsigned int leak_cnt = 0;
    st_ipoint *ret = NULL;

    for (size_t x = 0; layout[x] != NULL; ++x)
    {
        for (size_t y = 0; layout[x][y] != '\0'; ++y)
        {
            if (strchr(INNER, layout[x][y]))
            {
                if (
                        y == 0 || layout[x][y - 1] == ' ' ||
                        x == 0 || layout[x - 1][y] == ' ' ||
                        layout[x][y + 1] == '\0' || layout[x][y + 1] == ' ' ||
                        layout[x + 1] == NULL || layout[x + 1][y] == ' '
                        )
                {
                    ++leak_cnt;
                    ret = realloc(ret, sizeof (st_ipoint) * leak_cnt);
                    ret[leak_cnt - 1].x = x;
                    ret[leak_cnt - 1].y = y;
                }
            }
        }
    }

    return ret;
}

/**
 * Check if the map is invalid.
 * Receive the address for a t_cub instance then look into its map member to   
 * see if there are errors.
 * Possible errors are:
 *  - There is a line break between the map layout;
 *  - The map isn't surrounded by walls.
 *  - There are a invalid "id" in the map.
 * Case one of the above situations be verified, returns true to sinalize an   
 * error.
 * Erros like unknown element ids or more than one player or no player at all  
 * are handled by validate_elements.
 */
bool validate_map(st_cub *cub)
{
    st_ipoint *leaks;

    if (
            cub == NULL ||
            cub->layout == NULL ||
            cub->map_axis[AXIS_X] <= 2 ||
            cub->map_axis[AXIS_Y] <= 2
        )
    {
        return false;
    }
    
    leaks = look_arround(cub);
    if (leaks != NULL)
    {
        fprintf(stderr, "The map is not closed!\n");
        free(leaks);

        return false;
    }

    return true;
}
