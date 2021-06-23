/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_set_world.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:21:36 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/23 19:34:30 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_world.h"

/*
** Configure a t_world instance by the given t_cub buffer.
*/

t_world	*set_world(t_cub *cub, void *conn)
{
	t_tile		*tileset;
	t_sprite	*spriteset;
	t_world		*world;

	tileset = new_tile();
	spriteset = new_sprite();
	world = new_world();
	tileset->wall_no = new_img(cub->tilesheet->no_face, conn, 32, 32);
	tileset->wall_so = new_img(cub->tilesheet->so_face, conn, 32, 32);
	tileset->wall_we = new_img(cub->tilesheet->we_face, conn, 32, 32);
	tileset->wall_ea = new_img(cub->tilesheet->ea_face, conn, 32, 32);
	spriteset->sprite = new_img(cub->spritesheet->no_face, conn, 32, 32);
	world->tileset = tileset;
	world->spriteset = spriteset;
	world->floor = new_img("floor", conn, cub->res[0], cub->res[1] / 2);
	world->ceilling = new_img("ceilling", conn, cub->res[0], cub->res[1] / 2);
	world->map = cub->layout;
	world->map_x = cub->map_axis[0];
	world->map_y = cub->map_axis[1];
	world->player_x = cub->player_pos[0];
	world->player_y = cub->player_pos[1];
	return (world);
}
