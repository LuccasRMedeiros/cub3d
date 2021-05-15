/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:17:39 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/14 22:36:41 by lrocigno         ###   ########.fr       */
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

typedef struct	s_tile
{
	int		id;	// Defines what number represents this substitute
	char	*wall_no; // Defines what tile to draw when player is facing North
	char	*wall_so; // Defines what tile to draw when player is facing South
	char	*wall_we; // Defines what tile to draw when player is facing West
	char	*wall_ea; // Defines what tile to draw when player is facing East
}				t_tileset;

typedef struct	s_sprite
{
	int		id; // Defines what number represents its sprite
	char	*sprite; // Defines what texture to place
}				t_sprite;

typedef struct	s_map
{
	t_tile		*tileset;
	t_sprite	*spritesheet;
	int			map_x;
	int			map_y;
} 				t_map;

#endif
