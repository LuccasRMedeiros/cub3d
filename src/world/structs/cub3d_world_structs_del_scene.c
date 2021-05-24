/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_structs_del_scene.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:43:55 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/22 12:49:49 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Destroy a scene.
*/

#include "cub3d_world_structs.h"

void	del_scene(t_scene *del)
{
	t_map	*map;

	map = del->map;
	del_map(map);
	del->status = 0;
	del->res[0] = 0;
	del->res[1] = 0;
	free(del);
}