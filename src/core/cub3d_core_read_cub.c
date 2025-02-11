/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_read_cub.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:10:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/31 17:44:37 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_core.h"

#include <string.h>

/**
 * Call the function that deals with certain type of information.
 * The first verification it does is if the cub status is -1 which means an    
 * error was found on the given cub file. If it happens, the select case return
 * to continue the read of the cub file. It is done to prevent to grant the 
 * program will read a fil till the end, avoiding a memory leak.
 *
 * TODO: This if else tree is not necessary anymore
 */
static void select_case_line(char *line, st_cub *cub, int gnl_stts)
{
    if (cub->status == -1)
        return ;

    if (!strncmp(line, "R", 1))
        set_res(line, cub);
    else if (!strncmp(line, "NO", 2) || !strncmp(line, "SO", 2)
        || !strncmp(line, "WE", 2) || !strncmp(line, "EA", 2))
        set_tilesheet(line, cub);
    else if (!strncmp(line, "S", 1))
        set_spritesheet(line, cub);
    else if (!strncmp(line, "F", 1))
        set_floor_color(line, cub);
    else if (!strncmp(line, "C", 1))
        set_ceilling_color(line, cub);
    else if (cub->status == 8)
        set_map(line, cub, gnl_stts);
    else if (is_map_pattern(line))
        wrong_order(cub);
}

/**
 * Reads a informed .cub file, so it starts to set correct values for world    -
 * members.
 */
st_cub *read_cub(int argc, char **argv)
{
    st_cub *cub;
    int fd, gnl_stts;
    char *line;

    cub = new_cub();
    fd = validate_args(argc, argv);
    
    if (fd == -1)
    {
        cub->status = -1;
        return cub;
    }
    
    if (argc == 3)
        cub->save = 1; // TODO: Fix it, the fourth argument must be either '-s' or '--save', the argc is not a valid way to confirm
    
    gnl_stts = 1;
    
    while (gnl_stts)
    {
        gnl_stts = ft_gnl(fd, &line); // TODO: Enhance the cub parsing and/or make ft_gnl part of the project
        select_case_line(line, cub, gnl_stts); // TODO: Place a switch case here
        free(line);
    }
    
    close(fd);
    
    return cub;
}
