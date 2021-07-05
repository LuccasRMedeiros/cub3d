/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:37:32 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/04 20:09:46 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_core.h"

/*
** The functions here are called to deal with events (key been pressed).
*/

int	key_pressed(int key, t_program *prog)
{
	if (key == 0xff1b)
		close_program(prog);
	else if (key == 0x77)
		prog->wrld->player_y += 1;
	else if (key == 0x64)
		prog->wrld->player_x += 1;
	else if (key == 0x73)
		prog->wrld->player_y -= 1;
	else if (key == 0x61)
		prog->wrld->player_x -= 1;
	else
		printf("pressed key: \e[0;35m%x\e[0m\n", key);
	return (0);
}

int	key_released(int key, t_program *prog)
{
	printf("watching the window: \e[1;33m%p\e[0m\n", prog->wndw->conn);
	printf("you just realeased the key: \e[1;35m%i\e[0m\n", key);
	return (key);
}
