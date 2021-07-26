/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:37:32 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/25 18:52:15 by lrocigno         ###   ########.fr       */
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
	else if (key == FWRD)
		prog->player->move_frrr = 1;
	else if (key == REAR)
		prog->player->move_frrr = -1;
	else if (key == LEFT)
		prog->player->move_lfrt = 1;
	else if (key == RGHT)
		prog->player->move_lfrt = -1;
	else if (key == TLFT)
		prog->player->vsn_turn = -1;
	else if (key == TRGT)
		prog->player->vsn_turn = 1;
	return (0);
}

int	key_released(int key, t_program *prog)
{
	if (key == FWRD || key == REAR)
		prog->player->move_frrr = 0;
	else if (key == LEFT || key == RGHT)
		prog->player->move_lfrt = 0;
	else if (key == TLFT || key == TRGT)
		prog->player->vsn_turn = 0;
	return (0);
}

int	close_pressed(t_program *prog)
{
	close_program(prog);
	return (0);
}
