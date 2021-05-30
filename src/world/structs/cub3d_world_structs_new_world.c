/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_structs_new_world.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:17:28 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/29 20:46:34 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Create a new t_world.
*/

#include "cub3d_world_structs.h"

t_world	*new_world(void)
{
	t_world	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->name = NULL;
	new->status = 0;
	new->tileset = new_tile();
	new->spriteset = new_sprite();
	new->floor_color[0] = -1;
	new->floor_color[1] = -1;
	new->floor_color[2] = -1;
	new->ceilling_color[0] = -1;
	new->ceilling_color[1] = -1;
	new->ceilling_color[2] = -1;
	new->map = NULL;
	new->map_x = 0;
	new->map_y = 0;
	return (new);
}
