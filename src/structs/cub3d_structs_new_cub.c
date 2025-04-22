/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_cub.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:39:09 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/31 18:26:26 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/**
 * Creates a st_cub instance.
 * A st_cub is a buffer the program holds in the early stages of execution. It 
 * keeps information retrived by the informed cub file.
 */
st_cub *new_cub(void)
{
    st_cub *new;

    new = malloc(sizeof(*new));
    
    if (!new)
        return NULL;
    
    new->status = 0;
    new->res[0] = 0;
    new->res[1] = 0;
    new->tilesheet = new_sheet('1', 1);
    new->spritesheet = new_sheet('2', 0);
    new->f_color[0] = -1;
    new->f_color[1] = -1;
    new->f_color[2] = -1;
    new->c_color[0] = -1;
    new->c_color[1] = -1;
    new->c_color[2] = -1;
    new->layout_size = 0;
    new->pre_lyt = NULL;
    new->layout = NULL;
    new->map_axis[0] = 0;
    new->map_axis[1] = 0;
    new->player_pos[0] = 0;
    new->player_pos[1] = 0;
    
    return new;
}
