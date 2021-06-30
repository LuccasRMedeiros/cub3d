/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_print_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:35:25 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/27 14:43:56 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Draw the map on the screen.
*/

#include "cub3d_draw.h"

void	print_map(t_world *world, t_img *screen)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < world->map_x)
	{
		while (y < world->map_y)
		{
			if (world->map[x][y] == '1')
				draw_image(screen, y * 32, x * 32);
			++y;
		}
		y = 0;
		++x;
	}
}
