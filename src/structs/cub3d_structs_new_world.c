/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_world.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:17:28 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/22 13:30:46 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Return a color code.
** This color code is obtained by bit shifting the array rgb values.
*/

static int	color_picker(int rgb[3])
{
	int	r;
	int	g;
	int	b;

	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	return (r << 16 | g << 8 | b);
}

/*
** Create a new t_world using the informed t_cub
*/

t_world	*new_world(t_cub *cub)
{
	t_world	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->tileset = new_tile(cub->tilesheet);
	new->spriteset = new_sprite(cub->spritesheet);
	new->floor = color_picker(cub->f_color);
	new->ceilling = color_picker(cub->c_color);
	new->map = cub->layout;
	new->map_x = cub->map_axis[0];
	new->map_y = cub->map_axis[1];
	new->abs_x = new->map_x * TILESIZE;
	new->abs_y = new->map_y * TILESIZE;
	return (new);
}
