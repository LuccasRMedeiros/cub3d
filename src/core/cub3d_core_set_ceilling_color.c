/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_set_ceilling_color.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:47:06 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/27 13:39:41 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_core.h"

#include <string.h>

/**
 * Sets the ceilling color.
 * Receives a line and a world. The line is a string processed by the ft_gnl   -
 * and its assumed that when the program enters the function a "C" char can be -
 * found in the beging of such line.
 * The world is a address to an t_world instance.
 */
void set_ceilling_color(char *line, st_cub *cub)
{
    char *rgb[4];

    rgb[0] = strtok(line + 1, ","); // TODO: Substitute this by 'strtok' and avail if it might not cause crashes
    for (size_t i = 1; (rgb[i] = strtok(NULL, ",")) != NULL && i < 3; ++i);
    rgb[3] = NULL;

    if (
            !validate_color(rgb, "ceilling") ||
            !is_first_def(&cub->c_color[0], "Ceilling color", -1)
        )
    {
        cub->status = -1;
        
        return ;
    }
    cub->c_color[0] = atoi(rgb[0]);
    cub->c_color[1] = atoi(rgb[1]);
    cub->c_color[2] = atoi(rgb[2]);
    cub->status += 1;
}
