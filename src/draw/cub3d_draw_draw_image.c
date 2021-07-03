/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_draw_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:03:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/03 19:55:48 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Uses pixel_put to draw a image on the screen.
*/

void	draw_image(t_wndw *wndw, char *el, int org_x, int org_y)
{
	size_t	col;
	size_t	row;
	int		color;

	col = 0;
	row = 0;
	color = 0;
	if (*el == '1')
		color = 0xFFFFFF;
	else if (*el == '2')
		color = 0xFF0000;
	else if (*el == 'P')
		color = 0x0000FF;
	while (row < 32)
	{
		while (col < 32)
		{
			pixel_put(wndw->screen, row + org_x, col + org_y, color);
			++col;
		}
		col = 0;
		++row;
	}
	mlx_put_image_to_window(wndw->conn, wndw->wndw, wndw->screen->img, 0, 0);
}
