/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_sheet.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:37:12 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/04 20:37:02 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Creates a new t_sheet instance.
** t_sheet is a identificated list which contains the path for textures to     -
** north, south, west and east faces for both walls and sprites. The required  -
** id is how a tile or a sprite is identified in the cub layout.
*/

t_sheet	*new_sheet(char id, bool is_wall)
{
	t_sheet	*new;
	
	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->id = id;
	new->is_wall = is_wall;
	new->no_face = NULL;
	new->so_face = NULL;
	new->we_face = NULL;
	new->ea_face = NULL;
	return (new);
}
