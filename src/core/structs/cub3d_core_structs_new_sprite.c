/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_structs_new_sprite.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:56:31 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/20 17:58:03 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Initialize a new t_sprite.
*/

#include "cub3d_core_structs.h"

t_sprite	*new_sprite(void)
{
	t_sprite	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->id = 0;
	new->sprite = NULL;
	return (new);
}
