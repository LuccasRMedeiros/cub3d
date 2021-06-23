/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_world.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:17:28 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/23 18:36:32 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Create a new t_world.
*/

#include "cub3d_structs.h"

t_world	*new_world(void)
{
	t_world	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->tileset = NULL;
	new->spriteset = NULL;
	new->floor = NULL
	new->ceilling = NULL;
	new->map = NULL;
	new->map_x = 0;
	new->map_y = 0;
	return (new);
}
