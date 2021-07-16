/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:37:32 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/08 21:03:05 by lrocigno         ###   ########.fr       */
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
	printf("pressed key: \e[0;35m%x\e[0m\n", key);
	return (0);
}

int	key_released(int key, t_program *prog)
{
	printf("window address: \e[1;35m%p\e[0m\n", prog->wndw->conn);
	printf("released key: \e[0;35m%x\e[0m\n", key);
	return (0);
}
