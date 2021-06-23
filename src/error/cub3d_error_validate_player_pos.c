/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error_validate_player_pos.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:34:40 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/23 19:21:09 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_error.h"

/*
** If necessary, send an apropriate error message.
** Return false or true.
*/

static bool	send_msg(int p_cnt)
{
	if (p_cnt < 1)
	{
		error_msg("No player present in the given map", "Map");
		return (false);
	}
	else if (p_cnt > 1)
	{
		error_msg("More than one player present in the map", "Map");
		return (false);
	}
	else
		return (true);
}

/*
** Verify if there are only one player on map layout.
*/

bool	validate_player_pos(t_cub *cub)
{
	size_t	row;
	size_t	col;
	int		p_cnt;

	row = 0;
	col = 0;
	p_cnt = 0;
	while (cub->layout[row])
	{
		while (cub->layout[row][col])
		{
			if (ft_strhvchr(PLAYER, cub->layout[row][col]))
				++p_cnt;
			++col;
		}
		col = 0;
		++row;
	}
	return (send_msg(p_cnt));
}
