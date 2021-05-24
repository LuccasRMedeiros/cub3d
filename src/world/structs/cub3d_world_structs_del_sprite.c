/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_structs_del_sprite.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:04:02 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/24 15:07:43 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Destroy a t_sprite.
*/

#include "cub3d_world_structs.h"

void	del_sprite(t_sprite *del)
{
	char	*holder;

	holder = del->sprite;
	free(holder);
	del->id = 0;
	del->sprite = NULL;
	free(del);
}
