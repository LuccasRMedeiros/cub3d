/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_update_frame.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:51:56 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/25 01:57:20 by lrocigno         ###   ########.fr       */
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

	frame = new_img(prog->wndw, prog->wndw->wdt, prog->wndw->wdt, NULL);
	ray_cast(prog->wrld, prog->player, prog->wndw->wdt);
	draw_background(frame, prog->wndw, prog->wrld);
	render_projection(frame, prog->wrld, prog->wndw, prog->player);
	mlx_put_image_to_window(prog->wndw->conn,
		prog->wndw->wndw, frame->img, 0, 0);
	del_img(frame);
	free(prog->player->rays);
	return (0);
}
