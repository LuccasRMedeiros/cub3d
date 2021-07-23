/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_navigate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:18:26 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/23 00:58:52 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_world.h"

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
}
