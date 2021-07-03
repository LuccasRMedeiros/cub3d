/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_del_world.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 12:14:25 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/03 16:22:19 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Destroy a world.
*/

#include "cub3d_structs.h"

void	del_world(t_world *del)
{
	del_tile(del->tileset);
	del->tileset = NULL;
	del_sprite(del->spriteset);
	del->spriteset = NULL;
	del->floor = 0;
	del->ceilling = 0;
	ft_destroyer((void **)del->map);
	del->map_x = 0;
	del->map_y = 0;
	del->player_x = 0;
	del->player_y = 0;
	free(del);
}
