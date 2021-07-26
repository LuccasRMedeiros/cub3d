/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_navigate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:18:26 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/25 18:50:59 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_world.h"

/*
** Verify if the pretended movement is possible, if so adds delta_x to map_x   -
** and delta_y to map_y.
** It is used only to move foward or rear, the sig parameter rule which        -
** direction it is going to.
*/

static void	player_move_frrr(t_world *wrld, t_actor *player)
{
	double	n_ax;
	double	n_ay;
	int		n_mx;
	int		n_my;

	n_ax = player->abs_x + (player->delta_x * player->move_frrr);
	n_ay = player->abs_y + (player->delta_y * player->move_frrr);
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

static void	player_move_lfrt(t_world *wrld, t_actor *player)
{
	double	n_ax;
	double	n_ay;
	int		n_mx;
	int		n_my;

	n_ax = player->abs_x + (player->delta_xl * player->move_lfrt);
	n_ay = player->abs_y + (player->delta_yl * player->move_lfrt);
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

void    navigate(t_world *wrld, t_actor *player)
{
	player_move_frrr(wrld, player);
	player_move_lfrt(wrld, player);
}
