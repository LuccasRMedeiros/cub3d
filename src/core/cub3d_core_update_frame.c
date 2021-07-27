/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_update_frame.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:51:56 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/26 22:03:07 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_core.h"

/*
** Ask to ray_caster cast rays from the plaer postion then loop through the ray-
**  array and call draw_column to draw each column correspondent to each ray.
*/

int	update_frame(t_program *prog)
{
	t_img	*frame;

	frame = new_img(prog->wndw, prog->wndw->wdt, prog->wndw->hgt, NULL);
	if (prog->player->move_frrr || prog->player->move_lfrt)
		navigate(prog->wrld, prog->player);
	if (prog->player->vsn_turn)
		player_turn(prog->player);
	ray_cast(prog->wrld, prog->player, prog->wndw->wdt);
	draw_background(frame, prog->wndw, prog->wrld);
	render_projection(frame, prog->wrld, prog->wndw, prog->player);
	//render_sprite(frame, prog->sprite_list, prog->player, prog->nspt);
	mlx_put_image_to_window(prog->wndw->conn,
		prog->wndw->wndw, frame->img, 0, 0);
	del_img(frame);
	free(prog->player->rays);
	return (0);
}
