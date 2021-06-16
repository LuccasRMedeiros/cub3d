/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:10:14 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/16 13:53:57 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Execute the update of position for moving elements.
*/

#include "cub3d_core.h"

void	move(t_actor *obj, float trns_x, float trns_y)
{
	t_window	*wndw;
	int			move_to_x;
	int			move_to_y;

	wndw = get_window(NULL);
	move_to_x = obj->pos_x + trns_x;
	move_to_y = obj->pos_y + trns_y;
	mlx_put_image_to_window(wndw->conn, wndw->wndw_ptr, obj->sprite->img,
		move_to_x, move_to_y);
}
