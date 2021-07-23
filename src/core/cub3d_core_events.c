/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:37:32 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/23 01:51:45 by lrocigno         ###   ########.fr       */
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
	else if (key == FWRD || key == REAR || key == LEFT || key == RGHT)
		navigate(prog->wrld, prog->player, key);
	else if (key == TLFT || key == TRGT)
		player_turn(prog->player, key);
	return (0);
}

int	key_released(int key, t_program *prog)
{
	if (key == FWRD || key == REAR || key == LEFT || key == RGHT)
		navigate(prog->wrld, prog->player, key);
	return (0);
}

int	close_pressed(t_program *prog)
{
	close_program(prog);
	return (0);
}
