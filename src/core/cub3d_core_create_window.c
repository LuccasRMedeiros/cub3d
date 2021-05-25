/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_create_window.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:21:15 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/25 15:03:22 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Initialize the comunication between the X-window service and the program.
** Require a t_window instance with resolution configurations and passes the   -
** x-service address returned by mlx_init to wndw_ptr member.
*/

#include "cub3d_core.h"

void	create_window(t_window *window)
{
	window->wndw_ptr = mlx_init();
	if (!window->wndw_ptr)
		return ;
	mlx_new_window(window->wndw_ptr, window->res[0], window->res[1], "cub3D");
}
