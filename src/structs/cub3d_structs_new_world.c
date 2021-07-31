/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_world.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:17:28 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/30 14:46:08 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Count how many sprites are in the world.
*/

static int	cnt_sprites(char **map, int map_x, int map_y)
{
	int	cnt;
	int	x;
	int	y;

	cnt = 0;
	x = 0;
	y = 0;
	while (y < map_y)
	{
		while (x < map_x)
		{
			if (map[y][x] == '2')
				++cnt;
			++x;
		}
		++y;
		x = 0;
	}
	return (cnt);
}

/*
** Create a new t_world using the informed t_cub
*/

t_world	*new_world(t_cub *cub, t_wndw *wndw)
{
	t_world	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->tileset = new_tile(cub->tilesheet, wndw);
	new->spriteset = new_sprite(cub->spritesheet, wndw);
	new->floor = color_picker(cub->c_color);
	new->ceilling = color_picker(cub->f_color);
	new->map = cub->layout;
	new->map_x = cub->map_axis[0];
	new->map_y = cub->map_axis[1];
	new->abs_x = new->map_x * TILESIZE;
	new->abs_y = new->map_y * TILESIZE;
	new->n_sprites = cnt_sprites(new->map, new->map_x, new->map_y);
	return (new);
}
