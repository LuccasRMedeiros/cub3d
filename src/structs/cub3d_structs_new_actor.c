/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_actor.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:32:21 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/31 18:31:24 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/**
 * Will return a double value according to what char represent the player.
 * This char can be 'N', 'S', 'W' or 'E', they reffer to what direction the    -
 * player start looking to.
 * The function must be unreacheble if a invald direction be informed. It means-
 *  the return 0 is symbolic (also it turn possible the program to be compiled,-
 * another solution would be to return any of the values below out of the "if  -
 * else if" branch, but this way make things humanly readable).
 */
static double select_dir(char dir)
{
    switch (dir)
    {
    case 'W':
        return WEST;
    case 'N':
        return NORTH;
    case 'E':
        return EAST;
    case 'S':
        return SOUTH;
    default:
        break;
    }
    
    return 0;
}

/**
 * Create a new st_actor instance.
 * NOTE: Contain funny joke (well, it might be there in somewhere, but even i 
 * can't figure what it should be anymore).
 */
st_actor *new_actor(char dir, st_wndw *wndw, int pos_x, int pos_y)
{
    st_actor *new;

    new = malloc(sizeof(*new));
    
    if (!new)
        return NULL;
    
    new->id = 'P';
    new->map_x = pos_x;
    new->map_y = pos_y;
    new->abs_x = pos_x * TILESIZE + (TILESIZE / 2);
    new->abs_y = pos_y * TILESIZE + (TILESIZE / 2);
    new->dir = select_dir(dir);
    new->d_proj = (wndw->wdt / 2) / tan(FOV_ANG / 2);
    new->delta_x = cos(new->dir) * 5;
    new->delta_y = sin(new->dir) * 5;
    new->delta_xl = cos(normalize_angle(new->dir - (RDR * 90))) * 5;
    new->delta_yl = sin(normalize_angle(new->dir - (RDR * 90))) * 5;
    new->move_frrr = 0;
    new->move_lfrt = 0;
    new->vsn_turn = 0;
    
    return new;
}
