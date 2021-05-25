/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_print_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:35:25 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/25 11:52:17 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** It is like "do_nothing", a placeholder function to test compilation and see -
** everything is been parsing correctly.
*/

#include "cub3d_draw.h"

void	print_map(t_world *world)
{
	size_t	ln;
	char	**layout;

	ln = 0;
	layout = world->map->layout;
	while (layout[ln] != NULL)
	{
		printf("\e[1;31m%s\e[0m\n", layout[ln]);
		++ln;
	}
}
