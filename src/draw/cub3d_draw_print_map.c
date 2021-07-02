/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_print_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:35:25 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/01 21:24:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Draw the map on the screen.
*/

#include "cub3d_draw.h"

void	print_map(t_world *wrld, t_wndw *wndw)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < wrld->map_x)
	{
		while (y < wrld->map_y)
		{
			if (wrld->map[x][y] == '1')
				draw_image(wndw, y * 32, x * 32);
			++y;
		}
		y = 0;
		++x;
	}
}
