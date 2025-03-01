/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_set_res.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:55:23 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/23 22:23:28 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_core.h"

#include <string.h>

/**
 * Receive a line containing info about window resolution, check if it is all  
 * right, the sets the proper values for further configuration.
 * Does not return data, it will process all the information into a given st_cub
 * address.
 */
void set_res(char *line, st_cub *cub)
{
    char *res[3];

    res[0] = strtok(line + 1, " ");
    res[1] = strtok(NULL, " ");
    res[2] = NULL;

    if (
            !is_first_def((void *)cub->res, "Window resolution", 0) ||
            !validate_res(res)
        )
    {
        cub->status = -1;
    }
    cub->res[WDT] = atoi(res[0]);
    cub->res[HGT] = atoi(res[1]);
}
