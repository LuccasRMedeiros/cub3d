/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_del_cub.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:11:21 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/31 18:12:07 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/**
 * Delete a cub instance.
 */
void del_cub(st_cub *del)
{
    if (del->status == -1)
    {
        for (size_t row = 0; del->layout[row] != NULL; ++row)
            free (del->layout[row]);
        
        del->layout = NULL;
    }

    del->status = 0;
    del->res[0] = 0;
    del->res[1] = 0;
    del_sheet(del->tilesheet);
    del_sheet(del->spritesheet);
    del->tilesheet = NULL;
    del->spritesheet = NULL;
    del->f_color[0] = -1;
    del->f_color[1] = -1;
    del->f_color[2] = -1;
    del->c_color[0] = -1;
    del->c_color[1] = -1;
    del->c_color[2] = -1;
    
    free(del->pre_lyt);
    
    del->pre_lyt = NULL;
    del->map_axis[0] = 0;
    del->map_axis[1] = 0;
    del->player_pos[0] = 0;
    del->player_pos[1] = 0;
    
    free(del);
}
