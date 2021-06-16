/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_structs_new_actor.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:26:40 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/16 13:53:57 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Create a new actor instance.
*/

#include "cub3d_core_structs.h"

t_actor	*new_actor(char	id, int	pos_x, int pos_y)
{
	t_actor	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->id = id;
	new->pos_x = pos_x;
	new->pos_y = pos_y;
	new->sprite = NULL;
	return (new);
}
