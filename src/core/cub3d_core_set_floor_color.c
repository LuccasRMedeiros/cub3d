/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_set_floor_color.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:19:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/27 13:39:12 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_core.h"

#include <stdlib.h>
#include <string.h>

/**
 * Sets the floor color.
 * Receives a line and a world. The line is a string processed by the ft_gnl   -
 * and its assumed that when the program enters the function a "F" char can be -
 * found in the beging of such line.
 * The world is a address to an t_world instance.
 */
void set_floor_color(char *line, st_cub *cub)
{
    char *rgb[4];

    rgb[0] = strtok(line + 1, ",");
    for (size_t i = 1; (rgb[i] = strtok(NULL, ",")) != NULL && i < 3; ++i);
    rgb[3] = NULL;

    if (
            !validate_color(rgb, "floor") ||
            !is_first_def(&cub->f_color[0], "Floor color", -1)
        )
    {
        cub->status = -1;

        return ;
    }
    cub->f_color[0] = atoi(rgb[0]);
    cub->f_color[1] = atoi(rgb[1]);
    cub->f_color[2] = atoi(rgb[2]);
    cub->status += 1;
}
