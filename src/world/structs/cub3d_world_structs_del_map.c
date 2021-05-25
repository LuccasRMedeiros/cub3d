/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_structs_del_map.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 12:14:25 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/25 11:36:23 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Destroy a map.
*/

#include "cub3d_world_structs.h"

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
	ft_destroyer((void **)layout);
	free(name);
	name = NULL;
	del_tile(tileset);
	del_sprite(spriteset);
	del->tileset = NULL;
	del->spriteset = NULL;
	del->floor_color[0] = 0;
	del->floor_color[1] = 0;
	del->floor_color[2] = 0;
	del->ceilling_color[0] = 0;
	del->ceilling_color[1] = 0;
	del->ceilling_color[2] = 0;
	del->map_x = 0;
	del->map_y = 0;
	free(del);
}
