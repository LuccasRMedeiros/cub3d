/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_error_is_layout_pattern.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:49:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/24 13:53:11 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Confer if a line corresponds to a layout pattern, it means such line have a -
** sequence of elements.
** Requires a line which will be read. Return true if it is a layout pattern or-
**  false if not.
*/

#include "cub3d_world_error.h"

bool	is_layout_pattern(char *line)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (ft_strhvchr(ELEMENTS, line[i]))
			++y;
		++i;
	}
	if (y > 0)
		return (true);
	return (false);
}

