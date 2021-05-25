/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_structs_del_world.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:43:55 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/25 11:36:23 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Destroy a world.
*/

#include "cub3d_world_structs.h"

void	del_world(t_world *del)
{
	t_map	*map;

	map = del->map;
	del_map(map);
	del->status = 0;
	free(del);
}
