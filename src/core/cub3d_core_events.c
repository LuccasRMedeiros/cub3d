/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:37:32 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/16 13:53:57 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The functions here are called to deal with events (key been pressed).
*/

#include "cub3d_core.h"

int	key_pressed(int key, t_world *world, t_actor *player)
{
	if (key == 0xff1b)
		close_program(world);
	else if (key == 0x77)
		move(player, 1, 0);
	else if (key == 0x64)
		move(player, 0, 1);
	else if (key == 0x73)
		move(player, -1, 0);
	else if (key == 0x61)
		move(player, 0, -1);
	else
		printf("pressed key: \e[0;35m%x\e[0m\n", key);
	return (0);
}

int	key_released(int key, t_window *window)
{
	printf("Window: \e[0;35m%p\e[0m\n", window->wndw_ptr);
	printf("Key: \e[0;33m%x\e[0m released\n", key);
	return (0);
}
