/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_close_program.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 11:50:47 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/25 02:04:26 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Close a the program.
** Calls for get_window to obtain the main window informations, then delete the-
**  window and the received world.
** The close_program function is only called when the program had successfully -
** been executed.
*/

#include "cub3d_core.h"

int	close_program(t_program *prog)
{
	del_world(prog->wrld);
	del_window(prog->wndw);
	del_actor(prog->player);
	prog = NULL;
	exit(0);
}
