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

/**
 * Both walls_at_col and walls_at_row looks to each index at what it is meant  
 * look at from its beginning to its end and the reverse path also, it will    
 * assign 2 to "walls" var each time it find a wall, if it find a INNER element
 *  (02NSWE) it set walls to 1.
 * So each number returned from "walls_at" functions means:
 *  - 2: There are walls in both extremes and its interior is filled.
 *  - 1: There are no walls surrounding the interiors of the map.
 *  - 0: A empty column was found, and like the break lines between the map    
 * layout, they are invalid.
 */
static int walls_at_col(char **map, size_t col)
{
    int walls;

    walls = 0;

    for (int i = 0; map[i]; ++i)
    {
        if (map[i][col] == '1')
            walls = 2;
        else if (strpbrk(INNER, map[i][col]))
        {
            if (walls == 0 || map[i - 1][col] == ' ')
                return 1;

            walls = 1;
        }
        else if (!strpbrk(VLCHR, map[i][col]))
            return -1;
    }

    return walls;
}

static int walls_at_row(char *map)
{
    int walls;

    walls = 0;

    for (int i = 0; map[i]; ++i)
    {
        if (map[i] == '1')
            walls = 2;
        else if (strpbrk(INNER, map[i]))
        {
            if (walls == 0 || map[i - 1] == ' ')
                return 1;

            walls = 1;
        }
        else if (!strpbrk(VLCHR, map[i]))
            return -1;
    }

    return walls;
}

/**
 * Call walls_at_row and walls_at_col to check if there are walls surrounding  
 * the map.
 */
static int conf_walls(st_cub *cub)
{
    int walls;

    walls = 0;

    for (int r = 0; r < cub->map_axis[1]; ++r)
    {
        walls = walls_at_row(cub->layout[r]);

        if (walls != 2)
            return walls;
    }

    for (int c = 0; c < cub->map_axis[0]; ++c)
    {
        walls = walls_at_col(cub->layout, c);

        if (walls != 2)
            return walls;
    }

    return walls;
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
int validate_map(st_cub *cub)
{
    int cw;

    cw = conf_walls(cub);

    if (cw == 1)
    {
        error_msg("The map must be surrounded by walls", "map layout");

        return 0;
    }
    else if (cw == 0)
    {
        error_msg("Blank line found on map layout", "map layout");

        return 0;
    }
    else if (cw == -1)
    {
        error_msg("Invalid character in map layout", "map layout");

        return 0;
    }

    return 1;
}
