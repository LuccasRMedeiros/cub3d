/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_structs_new_scene.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:22:28 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/20 18:34:10 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Initialize a new scene.
*/

#include "cub3d_core_structs.h"

t_scene	*new_scene(void)
{
	t_scene	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->status = 0;
	new->res[0] = 0;
	new->res[1] = 0;
	new->map = new_map();
	return (new);
}
