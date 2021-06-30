/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_draw_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:03:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/27 13:14:00 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Uses pixel_put to draw a image on the screen.
*/

void	draw_image(t_img *frame, int org_x, int org_y)
{
	size_t	col;
	size_t	row;

	col = 0;
	row = 0;
	while (row < 32)
	{
		while (col < 32)
		{
			pixel_put(frame, row + org_x, col + org_y, 0xFFFFFF);
			++col;
		}
		col = 0;
		++row;
	}
}
