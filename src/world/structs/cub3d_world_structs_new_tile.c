/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_structs_new_tile.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:36:01 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/22 12:49:50 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Initialize a new t_tile structure.
*/

#include "cub3d_world_structs.h"

t_tile	*new_tile(void)
{
	t_tile	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->id = 0;
	new->wall_no = NULL;
	new->wall_so = NULL;
	new->wall_we = NULL;
	new->wall_ea = NULL;
	return (new);
}
