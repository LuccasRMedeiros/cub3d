/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_structs_del_map.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 12:14:25 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/19 13:23:35 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Destroy a map.
*/

#include "cub3d_core_structs.h"

void	destroy_layout(char **layout)
{
	size_t	lay_i;

	lay_i = 0;
	while (layout[lay_i] != NULL)
	{
		layout[lay_i] = NULL;
		free(layout[lay_i]);
		++lay_i;
	}
	free(layout);
}

void	del_map(t_map *del)
{
	char		*name;
	char		**layout;
	t_tile		*tileset;
	t_sprite	*spriteset;

	name = del->name;
	layout = del->layout;
	tileset = del->tileset;
	spriteset = del->spriteset;
	free(name);
	destroy_layout(layout);
	del_tile(tileset);
	del_sprite(spriteset);
	del->name = NULL;
	del->tileset = NULL;
	del->spriteset = NULL;
	del->floor_color[0] = 0;
	del->floor_color[1] = 0;
	del->floor_color[2] = 0;
	del->ceilling_color[0] = 0;
	del->ceilling_color[1] = 0;
	del->ceilling_color[2] = 0;
	del->layout = NULL;
	del->map_x = 0;
	del->map_y = 0;
	free(del);
}
