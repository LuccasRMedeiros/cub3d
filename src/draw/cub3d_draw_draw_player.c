/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_draw_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 19:32:08 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/03 20:01:18 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Takes the player position and draw a blue square representing it.
*/

void	draw_player(t_wndw *wndw, t_world *wrld)
{
	draw_image(wndw, "P", wrld->player_x * 32, wrld->player_y * 32);
}
