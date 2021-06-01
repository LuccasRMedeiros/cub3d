/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:37:32 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/31 17:31:51 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The functions here are called to deal with events (key been pressed).
*/

#include "cub3d_core.h"

int	key_pressed(int key, t_world *world)
{
	if (key == 0xff1b)
		close_window(world);
	return (0);
}

int	key_released(int key, t_window *window)
{
	printf("Window: \e[0;35m%p\e[0m\n", window->wndw_ptr);
	printf("Key: \e[0;33m%x\e[0m released\n", key);
	return (0);
}
