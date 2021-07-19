/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_set_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:58:53 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/16 16:57:45 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_core.h"

/*
** Search for the player.
** Only succed if there are one (and not more) player in the map.
*/

void	set_player(t_cub *cub)
{
	int	map_x;
	int	map_y;

	map_x = 0;
	map_y = 0;
	if (!validate_player_pos(cub))
	{
		cub->status = -1;
		return ;
	}
	while (map_y < cub->map_axis[Y])
	{
		while (map_x < cub->map_axis[X])
		{
			if (ft_strhvchr(PLAYER, cub->layout[map_y][map_x]))
			{
				cub->player_pos[X] = map_x;
				cub->player_pos[Y] = map_y;
			}
			++map_x;
		}
		map_x = 0;
		++map_y;
	}
}
