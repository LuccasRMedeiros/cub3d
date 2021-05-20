/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_structs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:20:11 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/20 18:39:02 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This headers groups all the structs definitions and its initializations and -
** destructions.
*/

#ifndef CUB3D_CORE_STRUCTS_H
# define CUB3D_CORE_STRUCTS_H

# include <libft.h>

typedef struct s_tile
{
	char	id;
	char	*wall_no;
	char	*wall_so;
	char	*wall_we;
	char	*wall_ea;
}	t_tile;

typedef struct s_sprite
{
	char	id;
	char	*sprite;
}	t_sprite;

typedef struct s_map
{
	t_tile			*tileset;
	t_sprite		*spriteset;
	unsigned char	floor_color[3];
	unsigned char	ceilling_color[3];
	char			**layout;
	size_t			map_x;
	size_t			map_y;
}	t_map;

typedef struct s_scene
{
	int		status;
	size_t	res[2];
	t_map	*map;
}	t_scene;

t_tile		*new_tile(void);
void		del_tile(t_tile *del);
t_sprite	*new_sprite(void);
void		del_sprite(t_sprite *del);
t_map		*new_map(void);
void		del_map(t_map *del);
t_scene		*new_scene(void);
void		del_scene(t_scene *del);

#endif
