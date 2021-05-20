/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_structs_new_map.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:17:28 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/20 18:37:19 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Create a new t_map.
*/

#include "cub3d_core_structs.h"

t_map	*new_map(void)
{
	t_map	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->tileset = new_tile();
	new->spriteset = new_sprite();
	new->floor_color[0] = 0;
	new->floor_color[1] = 0;
	new->floor_color[2] = 0;
	new->ceilling_color[0] = 0;
	new->ceilling_color[1] = 0;
	new->ceilling_color[2] = 0;
	new->layout = NULL;
	new->map_x = 0;
	new->map_y = 0;
	return (new);
}
