/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_close_program.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 11:50:47 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/01 14:21:34 by lrocigno         ###   ########.fr       */
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

int	close_program(t_world *world)
{
	t_program *wndw;

	wndw = get_program(NULL);
	del_window(wndw);
	del_world(world);
	exit(0);
}
