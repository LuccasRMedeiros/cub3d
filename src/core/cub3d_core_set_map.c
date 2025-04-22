/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_set_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:59:44 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/05 16:50:30 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_core.h"
#include "libft.h"

#include <string.h>
#include <stdlib.h>

/**
 * NOTE: Until now this must be the most complex routine i had found in the 
 * code. Its objective was to setup the map so cub3d could render it.
 * There is a lot of unecessary memory allocations, not so much strange 
 * normalizations, and use of "custom" functions that i added in libft. It looks
 * "overengineered", and certainly can be optimized.
 */

/**
 * Normalize the map filling the layout row with spaces, so cub3d can scan the
 * layout better
 *
 * NOTE: This process seems to be unecessary, as it is used only to validate the
 * layout, for now it will be here "deprecated" for the case i find use for it 
 * in the future
 */
__attribute__((unused)) static void normalize_map(st_cub *cub)
{
    char **map;
    int rowsz;

    map = cub->layout;
    
    for (int row = 0; row < cub->map_axis[1]; ++row)
    {
        rowsz = (int)strlen(map[row]);

        if (rowsz < cub->map_axis[0])
        {
            map[row] = realloc(map[row], cub->map_axis[0] * sizeof(char) + 1);

            for (rowsz = rowsz; rowsz < cub->map_axis[0]; ++rowsz)
            {
                map[row][rowsz] = ' ';
            }
        }
    }
}

/**
 * Set the map, the axes, normalize it, then verify if it is build correctly.
 * The verification is only made in the end of the parsing to let ft_gnl finish-
 *  the read of the cub file, avoiding the static buffer to retain unecessary  -
 * data.
 * even when the program had closed due to some error.
 * Requires a line and a world. The line is a string processed by ft_gnl, is   -
 * assumed that when the program enters this function is because a serie of    -
 * elements (0, 1, 2 etc.) were found.
 * The world is a address to a t_world instance.
 *
 * TODO: Try to find a more optimal way to parse the map
 */
void set_map(char *line, st_cub *cub, size_t gnl_stts)
{
    if (gnl_stts && is_map_pattern(line))
    {
        int line_size = strlen(line);

        cub->layout_size++;
        cub->layout = realloc(cub->layout, sizeof (char *) * cub->layout_size + 1);
        cub->layout[cub->layout_size - 1] = strdup(line);
        cub->layout[cub->layout_size] = NULL;

        if (line_size > cub->map_axis[AXIS_X])
            cub->map_axis[AXIS_X] = line_size;

        cub->map_axis[AXIS_Y] = cub->layout_size;
    }
    else if (!gnl_stts)
    {
        if (!validate_map(cub))
        {
            cub->status = -1;

            return ;
        }
        
        cub->status += 12;
        set_player(cub);
    }
}
