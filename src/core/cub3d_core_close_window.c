/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_close_window.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 11:50:47 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/31 17:33:27 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Close a informed window.
** If no window is informed, it calls for ret_window to obtain one, even if    -
** ret_window doesn't return a window, then it will return -1 to inform a      -
** problem for the program.
** When everything goes all right, it call for mlx_destroy_window and finally  -
** destroy the t_window instance and return 0.
*/

#include "cub3d_core.h"

int	close_window(t_world *world)
{
	t_window *wndw;

	wndw = ret_window(NULL);
	if (!wndw)
		return (-1);
	mlx_destroy_window(wndw->con_ptr, wndw->wndw_ptr);
	del_window(wndw);
	del_world(world);
	exit(0);
}
