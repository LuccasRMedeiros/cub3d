/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_print_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:35:25 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/28 18:31:21 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** A placeholder, but this one helps checking if the map was correctly parsed.
*/

#include "cub3d_draw.h"

void	print_map(t_world *world)
{
	size_t	ln;
	char	**map;

	ln = 0;
	map = world->map;
	while (map[ln] != NULL)
	{
		printf("\e[1;31m%s\e[0m\n", map[ln]);
		++ln;
	}
}
