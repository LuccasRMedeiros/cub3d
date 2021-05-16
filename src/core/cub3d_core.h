/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:17:39 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/16 20:23:32 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Header containing all the core functions of cub3D.
*/

#ifndef CUB3D_CORE_H
# define CUB3D_CORE_H

# include <libft.h>
# include <math.h>
# include <stdio.h>
# include <cub3d_error.h>

typedef struct	s_tile
{
	unsigned int	id;	// Defines what char represents this tile
	char			*wall_no; // North cube face texture
	char			*wall_so; // South cube face texture
	char			*wall_we; // West cube face texture
	char			*wall_ea; // East cube face texture
}				t_tileset;

typedef struct	s_sprite
{
	unsigned int	id; // Defines what number represents its sprite
	char			*sprite; // Sprite texture
}				t_sprite;

typedef struct	s_map
{
	char			*name;
	t_tile			*tileset; // Array of tiles
	t_sprite		*spriteset; // Array of sprites
	char			**layout; // Array of lines found in .cub file
	size_t			map_x; // Height
	size_t			map_y; // Width
} 				t_map;

typedef struct	s_scene
{
	size_t			res[2]; // Width of the window to draw the scene
	unsigned char	floor_color[3]; // Color of the floor
	unsigned char	ceilling_color[3]; // Color of the ceiling
	t_map			*map; // The map to be drawed
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
