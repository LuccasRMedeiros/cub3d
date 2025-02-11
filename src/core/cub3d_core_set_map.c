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

#include <string.h>
#include <stdlib.h>

/**
 * NOTE: Until now this must be the most complex routine i had found in the 
 * code. Its objective was to setup the map in the cub structure for the program
 * to render it then.
 * There is a lot of unecessary memory allocations, not so much strange 
 * normalizations, and use of "custom" functions that i added in libft. It looks
 * "overengineered", and certainly can be optimized.
 */

/**
 * normalize_map will grant that all the lines have the same amount of columns -
 * by addind blank spaces till the end of the line.
 * It uses the map_x value as reference to calculate how much blank spaces are -
 * needed to normalize such line.
 * filler auxiliate normalize_map generating a string filled with blank spaces -
 * which will be concatenated in the line.
 */
static char *filler(int spcs)
{
    char *fill;

    fill = calloc(spcs, sizeof (char *));

    if (!fill)
        return NULL;

    --spcs;
    while (spcs >= 0)
    {
        fill[spcs] = ' ';
        --spcs;
    }

    return fill;
}

static void normalize_map(st_cub *cub)
{
    char **map;
    char *fill;
    size_t rowsz;

    map = cub->layout;
    
    for (int row = 0; row < cub->map_axis[1]; ++l)
    {
        rowsz = strlen(map[row]);

        if (rowsz < cub->map_axis[0])
        {
            map[row] = realloc(map[row], cub->map_axis[0] * sizeof(char) + 1);
            for (rowsz; rowsz < cub->map_axis[0]; ++rowsz)
            {
                map[rowsz] = ' ';
            }
        }
        ++l;
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
    size_t x = 0; y = 0;

    map = cub->layout;

    while (*map != NULL)
    {
        ++y;
        ++*map;
    }

    cub->map_axis[1] = y;
    
    for (int y = cub->map_axis[1]; y > 0; --y)
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
void set_map(const char *line, st_cub *cub, size_t gnl_stts)
{
    if (gnl_stts && is_map_pattern(line))
    {
        if (!cub->pre_lyt)
            cub->pre_lyt = calloc(1, sizeof(char *));

        cub->pre_lyt = realloc(cub->pre_lyt, sizeof(char) * strlen(line) + 2);
        if (cub->pre_lyt == NULL) { exit(-1); }
        cub->pre_lyt = strcat(cub->pre_lyt, line);
        cub->pre_lyt = strcat(cub->pre_lyt, "\n");
    }
    else if (!gnl_stts || cub->pre_lyt)
    {
        cub->layout = ft_split(cub->pre_lyt, '\n'); // this function will be kept for now
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
