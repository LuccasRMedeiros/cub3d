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
#include "libft.h"

#include <string.h>
#include <unistd.h>

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
    
    if (argc == 3 && (strcmp(argv[2], "-s") == 0 || strcmp(argv[2], "--save") == 0))
        cub->save = 1; 
    
    gnl_stts = 1;
    
    while (gnl_stts)
    {
        gnl_stts = mkr_read_line(fd, &line); // TODO: Enhance the cub parsing and/or make ft_gnl part of the project

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

        free(line);

        if (cub->status == -1)
            return cub;
    }
    
    close(fd);
    
    return cub;
}
