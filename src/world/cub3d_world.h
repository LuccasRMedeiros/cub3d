/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 11:44:11 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/31 19:04:12 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Header with the difinitions and prototypes for world pre-building functions.
 */

#ifndef CUB3D_WORLD_H
#define CUB3D_WORLD_H

#include <cub3d_structs.h>

void navigate(st_world *wrld, st_actor *player);
void player_turn(st_actor *player);
void analyze_sprites(
        st_wndw *wndw,
        st_world *wrld,
        st_actor *p,
        st_static_obj *spt_list);

#endif
