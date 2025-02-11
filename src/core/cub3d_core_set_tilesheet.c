/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_set_tilesheet.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:26:26 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/25 15:53:15 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_core.h"

#include <string.h>

/**
 * set_wall auxiliates set_tilesheet verificating a double definition for a     
 * given wall (as a char *).
 * dst should point to the actual address of a member of tileset, src is the   
 * data to be placed into that member.
 * The address to the world instance is used to make possible to set the status
 * case something went wrong.
 */
static void set_wall(st_cub *cub, char *path, char **face)
{
    if (
            !is_first_def(*face, "wall texture", 0) ||
            !validate_texture(path, "wall texture")
        )
    {
        path = NULL;
        return ;
    }

    *face = calloc(strlen(path) + 1, sizeof(char));
    strcpy(*face, path);
    cub->status += 1;
}

/**
 * Configure a tilesheet.
 * First verify which wall face it should set, then call the sub function      
 * set_wall.
 */
void set_tilesheet(char *line, st_cub *cub)
{
    char *path;

    path = strchr(line, '.');
    if (!strncmp(line, "NO", 2))
        set_wall(cub, path, &cub->tilesheet->no_face);
    else if (!strncmp(line, "SO", 2))
        set_wall(cub, path, &cub->tilesheet->so_face);
    else if (!strncmp(line, "WE", 2))
        set_wall(cub, path, &cub->tilesheet->we_face);
    else if (!strncmp(line, "EA", 2))
        set_wall(cub, path, &cub->tilesheet->ea_face);
}
