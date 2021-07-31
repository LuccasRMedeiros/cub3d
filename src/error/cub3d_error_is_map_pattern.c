/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error_is_map_pattern.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:49:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/31 17:56:26 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_error.h"

/*
** Confer if a line corresponds to a map pattern, it means such line have a    -
** sequence of elements.
** Requires a line which will be read. Return true if it is a map pattern or   -
** false if not.
*/

bool	is_map_pattern(const char *line)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (ft_strhvchr(VLCHR, line[i]))
			++y;
		else if (line[i] != ' ')
			return (false);
		++i;
	}
	if (y > 0)
		return (true);
	return (false);
}
