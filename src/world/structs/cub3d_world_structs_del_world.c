/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_structs_del_world.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 12:14:25 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/28 19:15:45 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Destroy a world.
*/

#include "cub3d_world_structs.h"

void	del_world(t_world *del)
{
	char		*name;
	char		**map;
	t_tile		*tileset;
	t_sprite	*spriteset;

	name = del->name;
	map = del->map;
	tileset = del->tileset;
	spriteset = del->spriteset;
	ft_destroyer((void **)map);
	free(name);
	name = NULL;
	ft_bzero(del->floor_color, 3);
	ft_bzero(del->ceilling_color, 3);
	del_tile(tileset);
	del_sprite(spriteset);
	del->status = 0;
	del->tileset = NULL;
	del->spriteset = NULL;
	del->map_x = 0;
	del->map_y = 0;
	free(del);
}
