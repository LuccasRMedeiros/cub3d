/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_player_turn.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 00:36:41 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/25 18:50:08 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_world.h"

/*
** Add or subtract from "player->dir", and calculate the delta_x, delta_y and  -
** "delta left" versions of those, it is, the player sine and cosine of player -
** direction angle less 90°.
** NOTE¹: the function always "sum" to player dir, so if a negative number be  -
** passed as an argument the direction of rotation will change. So the signal  -
** of dir is what tells which direction the player is turning, negative turns  -
** to left, positive turns to right.
** NOTE²: those deltas are values to be added to player position in order to   -
** make him move accordinly to its face direction.
** NOTE³: RDR is one degree in radians (PI divided by 180), it is defined in   -
** cub3d_structs.h.
** NOTE⁴: SOUTH is equal PI divided by 2, it is defined in cub3d_structs.h.
*/

void	player_turn(t_actor *player)
{
	float	dir;

	dir = RDR * player->vsn_turn;
	player->dir = normalize_angle(player->dir + dir);
	player->delta_x = cos(player->dir) * 5;
	player->delta_y = sin(player->dir) * 5;
	player->delta_xl = cos(normalize_angle(player->dir - SOUTH)) * 5;
	player->delta_yl = sin(normalize_angle(player->dir - SOUTH)) * 5;
}
