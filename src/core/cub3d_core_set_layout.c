/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_set_layout.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:59:44 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/19 20:18:58 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Set the map layout, then verify if it is made correctly.
** The verification is only made in the end of the parsing to let ft_gnl finish-
**  the read of the cub file, avoiding the static buffer to retain unecessary  -
** data.
** even when the program had closed due to some error.
** Requires a line and a scene. The line is a string processed by ft_gnl, is   -
** assumed that when the program enters this function is because a serie of    -
** tile id's (0, 1, 2 etc.) were found.
** The scene is a address to a t_scene instance.
*/

#include "cub3d_core.h"

static bool	is_layout_pattern(char *line)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (line[i] != '\n' || line[i] != '\0')
	{
		if (ft_strhvchr(ELEMENTS, line[i]))
			++y;
		++i;
	}
	if (y > 0)
		return (true);
	return (false);
}

void	set_layout(char *line, t_scene *scene, size_t gnl_stts)
{
	size_t	map_x;

	map_x = scene->map->map_x;
	if (is_layout_pattern(line))
	{
		scene->map->layout[map_x] = line;
		scene->map->map_x += 1;
	}
	else if (!gnl_stts)
		scene->status += 10;
	if (scene->status == 20)
		do_nothing();
}
