/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_turn.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 00:36:41 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/23 00:57:48 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_world.h"

/*
** Add or subtract from "player->dir", then test if it make a complete turn, if-
**  it is the case, set/reset the value of "player->dir" to 2PI (see 
** cub3d_structs.h) and finally calculate the delta_x and delta_y.
** Note¹: the function always "sum" to player dir, so if a negative number be  -
** passed as an argument the direction of rotation will change. So the signal  -
** of dir is what tells which direction the player is turning, negative turns  -
** to left, positive turns to right.
** Note²: delta_x and delta_y are values to be added to pĺayer position in     -
** order to make him move.
*/

void	player_turn(t_actor *player, int key)
{
	float	dir;

	dir = RDR;
	if (key == TLFT)
		dir *= -1;
	player->dir = normalize_angle(player->dir + dir);
	player->delta_x = cos(player->dir) * 5;
	player->delta_y = sin(player->dir) * 5;
	player->delta_xl = cos(normalize_angle(player->dir - (RDR * 90))) * 5;
	player->delta_yl = sin(normalize_angle(player->dir - (RDR * 90))) * 5;
}
