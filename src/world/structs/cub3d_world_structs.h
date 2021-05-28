/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_structs.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:20:11 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/28 20:00:39 by lrocigno         ###   ########.fr       */
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

typedef struct s_world
{
	char			*name;
	int				status;
	t_tile			*tileset;
	t_sprite		*spriteset;
	unsigned char	floor_color[3];
	unsigned char	ceilling_color[3];
	char			**map;
	size_t			map_x;
	size_t			map_y;
}	t_world;

t_tile		*new_tile(void);
void		del_tile(t_tile *del);
t_sprite	*new_sprite(void);
void		del_sprite(t_sprite *del);
t_world		*new_world(void);
void		del_world(t_world *del);

#endif
