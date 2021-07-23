/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_draw_wall.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:16:09 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/23 20:10:14 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Select a proper texture to be drawn on the screen.
*/

char	*select_wall(t_world *wrld, t_wndw *wndw, t_ray ray)
{
	char	*img_path;

	if (ray.id == 'H')
	{
		if (ray.dirs[UPDN])
			img_path = wrld->tileset->wall_so;
		else
			img_path = wrld->tileset->wall_no;
	}
	else if (ray.id == 'V')
	{
		if (ray.dirs[LTRT])
			img_path = wrld->tileset->wall_ea;
		else
			img_path = wrld->tileset->wall_we;
	}
	return (img_path);
}
