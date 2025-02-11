/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_del_tile.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:51:22 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/24 13:14:42 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/**
 * Destroy a t_tile.
 */
void del_tile(st_tile *del)
{
    del->id = 0;
    del_img(del->wall_no);
    del_img(del->wall_so);
    del_img(del->wall_we);
    del_img(del->wall_ea);
   
    free(del);
}
