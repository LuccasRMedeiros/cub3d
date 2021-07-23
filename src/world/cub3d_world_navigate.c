/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_navigate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:18:26 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/23 00:21:06 by lrocigno         ###   ########.fr       */
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

static void	player_turn(t_actor *player, double dir)
{
	player->dir = normalize_angle(player->dir + dir);
	player->delta_x = cos(player->dir) * 5;
	player->delta_y = sin(player->dir) * 5;
	player->delta_xl = cos(normalize_angle(player->dir - (RDR * 90))) * 5;
	player->delta_yl = sin(normalize_angle(player->dir - (RDR * 90))) * 5;
}

/*
** Verify if the pretended movement is possible, if so adds delta_x to map_x   -
** and delta_y to map_y.
** It is used only to move foward or rear, the sig parameter rule which        -
** direction it is going to.
*/

static void	player_move_fr(t_actor *player, t_world *wrld, int sig)
{
	double	n_ax;
	double	n_ay;
	int		n_mx;
	int		n_my;

	n_ax = player->abs_x + (player->delta_x * sig);
	n_ay = player->abs_y + (player->delta_y * sig);
	n_mx = n_ax / TILESIZE;
	n_my = n_ay / TILESIZE;
	if (wrld->map[player->map_y][n_mx] != '1')
	{
		player->abs_x = n_ax;
		player->map_x = n_mx;
	}
	if (wrld->map[n_my][player->map_x] != '1')
	{
		player->abs_y = n_ay;
		player->map_y = n_my;
	}
}

/*
** Similar to player_move_fr, but to make sidewalks.
*/

static void	player_move_lr(t_actor *player, t_world *wrld, int sig)
{
	double	n_ax;
	double	n_ay;
	int		n_mx;
	int		n_my;

	n_ax = player->abs_x + (player->delta_xl * sig);
	n_ay = player->abs_y + (player->delta_yl * sig);
	n_mx = n_ax / TILESIZE;
	n_my = n_ay / TILESIZE;
	if (wrld->map[player->map_y][n_mx] != '1')
	{
		player->abs_x = n_ax;
		player->map_x = n_mx;
	}
	if (wrld->map[n_my][player->map_x] != '1')
	{
		player->abs_y = n_ay;
		player->map_y = n_my;
	}
}

/*
** It is called after the player pressed a command. The function will receive  -
** such command and then calculate the proper movementation of the player.
** To calc, it take the angle the player is looking to verify if the next tile -
** is collidable and only if not, it make a change in the player position.
** Case the command be the configured "g_exit" or a out of context key the     -
** program must not enter this function.
** The last "else if" of the branch exists to make the code humanly readable.
*/

void    navigate(t_world *wrld, t_actor *player, int key)
{
	if (key == FWRD)
		player_move_fr(player, wrld, 1);
	else if (key == REAR)
		player_move_fr(player, wrld, -1);
	else if (key == RGHT)
		player_move_lr(player, wrld, -1);
	else if (key == LEFT)
		player_move_lr(player, wrld, 1);
	else if (key == TRGT)
		player_turn(player, RDR);
	else if (key == TLFT)
		player_turn(player, -RDR);
}
