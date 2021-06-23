/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_set_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:58:53 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/23 12:23:49 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_core.h"

/*
** Search for the player.
** Only succed if there are one (and not more) player in the map.
*/

void	set_player(t_cub *cub)
{
	size_t	map_x;
	size_t	map_y;

	map_x = 0;
	map_y = 0;
	if (!validate_player_pos(cub))
	{
		cub->status = -1;
		return ;
	}
	while (map_x < cub->axis[0])
	{
		while (map_y < cub->axis[1])
		{
			if (ft_strhvchr(PLAYER, cub->layout[map_x][map_y]))
			{
				cub->player_pos[0] = map_x;
				cub->player_pos[1] = map_y;
			}
			++map_y;
		}
		map_y = 0;
		++map_x;
	}
}
