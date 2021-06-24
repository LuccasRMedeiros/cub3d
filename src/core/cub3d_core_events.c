/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:37:32 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/24 14:31:54 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The functions here are called to deal with events (key been pressed).
*/

#include "cub3d_core.h"

int	key_pressed(int key, t_program *prog)
{
	if (key == 0xff1b)
		close_program(prog);
	else if (key == 0x77)
		printf("move foward\n");
	else if (key == 0x64)
		printf("move to right\n");
	else if (key == 0x73)
		printf("move backward\n");
	else if (key == 0x61)
		printf("move to left\n");
	else
		printf("pressed key: \e[0;35m%x\e[0m\n", key);
	return (0);
}

int	key_released(int key, t_program *prog)
{
	printf("Window: \e[0;35m%p\e[0m\n", prog->wndw->wndw_ptr);
	printf("Key: \e[0;33m%x\e[0m released\n", key);
	return (0);
}
