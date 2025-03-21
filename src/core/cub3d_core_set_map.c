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
 *
 * TODO:
 *  - Open and read the cub file line by line
 *  - Remove the realloc part and use strtok instead
 */

/**
 * Normalize the map filling the layout row with spaces, so cub3d can scan the
 * layout better
 */
static void normalize_map(st_cub *cub)
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
 * set_axes is a part of set_map where map_x and map_y are defined. It is      -
 * organized this way to allow check_invalid_map do its verification in the    -
 * already parsed data, garanting a better use of memory and processing.
 */
static void set_axes(st_cub *cub)
{
    char **map;
    int x = 0, y = 0;

    map = cub->layout;

    while (*map != NULL)
    {
        ++y;
        ++*map;
    }

    cub->map_axis[1] = y;
    
    for (y = y; y > 0; --y)
    {
        x = strlen(map[y]);

        if (x > cub->map_axis[0])
            cub->map_axis[0] = x;
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
    size_t sz_pre_lyt = 0;

    if (gnl_stts && is_map_pattern(line))
    {
        if (!cub->pre_lyt)
        {
            sz_pre_lyt = strlen(line) + 2;
            cub->pre_lyt = calloc(sz_pre_lyt, sizeof(char *));
        }
        else
        {
            char *pre_lyt;

            sz_pre_lyt = strlen(cub->pre_lyt) + strlen(line) + 2;
            pre_lyt = calloc(sz_pre_lyt, sizeof (char));

            strcpy(pre_lyt, cub->pre_lyt);
            free(cub->pre_lyt);
            cub->pre_lyt = pre_lyt;
        }

        if (cub->pre_lyt == NULL) { exit(-1); }

        strcat(cub->pre_lyt, line);
        strcat(cub->pre_lyt, "\n");
    }
    else if (!gnl_stts || cub->pre_lyt)
    {
        cub->layout = ft_split(cub->pre_lyt, '\n');
        set_axes(cub);
        normalize_map(cub);
        
        if (!validate_map(cub))
        {
            cub->status = -1;

            return ;
        }
        
        cub->status += 12;
        set_player(cub);
    }
}
