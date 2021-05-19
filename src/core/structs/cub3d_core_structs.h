/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_structs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:20:11 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/19 12:04:07 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This headers groups all the structs definitions and its initializations and -
** destructions.
*/

#ifndef CUB3D_CORE_STRUCTS_H
# define CUB3D_CORE_STRUCTS_H

# include <stdlib.h>

typedef struct	s_tile
{
	char	id;	// Defines what char represents this tile
	char	*wall_no; // North cube face texture
	char	*wall_so; // South cube face texture
	char	*wall_we; // West cube face texture
	char	*wall_ea; // East cube face texture
}				t_tile;

typedef struct	s_sprite
{
	char	id; // Defines what number represents its sprite
	char	*sprite; // Sprite texture
}				t_sprite;

typedef struct	s_map
{
	char			*name;
	t_tile			*tileset; // Array of tiles
	t_sprite		*spriteset; // Array of sprites
	unsigned char	floor_color[3]; // Color of the floor
	unsigned char	ceilling_color[3]; // Color of the ceiling
	char			**layout; // Array of lines found in .cub file
	size_t			map_x; // Height
	size_t			map_y; // Width
} 				t_map;

typedef struct	s_scene
{
	int		status; // Tells the program if it can continue or must stop
	size_t	res[2]; // Width of the window to draw the scene
	t_map	*map; // The map to be drawed
}				t_scene;

t_tile		*new_tile(void);
void		del_tile(t_tile *del);
t_sprite	*new_sprite(void);
void		del_sprite(t_sprite *del);
t_map		*new_map(void);
void		del_map(t_map *del);
t_scene		*new_scene(void);
void		del_scene(t_scene *del);

#endif
