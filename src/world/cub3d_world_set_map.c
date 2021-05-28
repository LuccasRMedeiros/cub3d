/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_set_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:59:44 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/28 19:08:36 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_world.h"

/*
** normalize_map will grant that all the lines have the same amount of columns -
** by addind blank spaces till the end of the line.
** It uses the map_x value as reference to calculate how much blank spaces are -
** needed to normalize such line.
** filler auxiliate normalize_map generating a string filled with blank spaces -
** which will be concatenated in the line.
*/

static char	*filler(int spcs)
{
	char	*fill;

	fill = ft_calloc(spcs, sizeof (char *));
	if (!fill)
		return (NULL);
	--spcs;
	while (spcs >= 0)
	{
		fill[spcs] = ' ';
		--spcs;
	}
	return (fill);
}

static void	normalize_map(t_world *world)
{
	char	**map;
	char	*fill;
	size_t	l;
	size_t	lsz;

	map = world->map;
	l = 0;
	while (l < world->map_y)
	{
		lsz = ft_strlen(map[l]);
		if (lsz < world->map_x)
		{
			lsz = (world->map_x - lsz) + 1;
			fill = filler(lsz);
			map[l] = ft_reallocncat(map[l], fill);
			free(fill);
			fill = NULL;
		}
		++l;
	}
}

/*
** set_axes is a part of set_map where map_x and map_y are defined. It is      -
** organized this way to allow check_invalid_map do its verification in the    -
** already parsed data, garanting a better use of memory and processing.
*/

static void	set_axes(t_world *world)
{
	char	**map;
	size_t	x;
	size_t	y;

	map = world->map;
	x = 0;
	y = ft_strstrlen(map);
	world->map_y = y;
	while (y > 0)
	{
		x = ft_strlen(map[y]);
		if (x > world->map_x)
			world->map_x = x;
		--y;
	}
}

/*
** Set the map map, the axes, normalize it, then verify if it is build         -
** correctly.
** The verification is only made in the end of the parsing to let ft_gnl finish-
**  the read of the cub file, avoiding the static buffer to retain unecessary  -
** data.
** even when the program had closed due to some error.
** Requires a line and a world. The line is a string processed by ft_gnl, is   -
** assumed that when the program enters this function is because a serie of    -
** elements (0, 1, 2 etc.) were found.
** The world is a address to a t_world instance.
*/

void	set_map(const char *line, t_world *world, size_t gnl_stts)
{
	static char	*map;

	if (!map)
		map = ft_calloc(1, sizeof(char));
	if (gnl_stts && is_map_pattern(line))
	{
		map = ft_reallocncat(map, line);
		map = ft_reallocncat(map, "\n");
	}
	else if (!gnl_stts || *map)
	{
		world->map = ft_split(map, '\n');
		free(map);
		map = NULL;
		set_axes(world);
		normalize_map(world);
		if (!validate_map(world))
		{
			world->status = -1;
			return ;
		}
		world->status += 12;
	}
}
