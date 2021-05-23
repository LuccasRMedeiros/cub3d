/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_set_layout.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:59:44 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/22 21:43:38 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_world.h"

/*
** is_layout_pattern verifies if a line corresponds at the expected pattern for-
**  a map layout, this means the line contains at least on element char. 
*/

static bool	is_layout_pattern(char *line)
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

/*
** normalize_map will grant that all the lines have the same amount of columns -
** by addind blank spaces till the end of the line.
** It uses the map_x value as reference to calculate how much blank spaces are -
** needed to normalize such line.
** filler is used as subfunction of normalize_map, it is called to help        -
** normalize map generating a string filled with blank spaces which will be    -
** concatenated in the lines.
*/

static char	filler(size_t spcs)
{
	char	*fill;

	fill = ft_calloc(spcs, sizeof (char *))
	if (!fill)
		return (NULL);
	--spcs
	while (spcs > 0)
	{
		fill[spcs] = ' ';
		--spcs;
	}
	return (fill);
}

static void	normalize_map(t_scene *scene)
{
	char	**layout;
	char	*fill;
	size_t	l;
	size_t	lsz;

	layout = scene->map->layout;
	l = 0;
	while (l < scene->map->map_y)
	{
		lsz = ft_strlen(layout[l]);
		if (lsz < scene->map->map_x)
		{
			lsz = (scene->map->map_x - lsz) + 1;
			fill = filler(lsz);
			layout[l] = ft_reallocncat(layout[l], fill);
			free(fill);
			fill = NULL;
		}
		++l;
	}
}

/*
** set_axes is a part of set_layout where map_x and map_y are defined. It is   -
** organized this way to allow check_invalid_layout do its verification in the -
** already parsed data, garanting a better use of memory and processing.
*/

static void	set_axes(t_scene *scene)
{
	char	**layout;
	size_t	x;
	size_t	y;

	layout = scene->map->layout;
	x = 0;
	y = ft_strstrlen(layout);
	scene->map->map_y = y;
	while (y > 0)
	{
		x = ft_strlen(layout[y]);
		if (x > scene->map->map_x)
			scene->map->map_x = x;
		--y;
	}
}

/*
** Set the map layout, the axes, normalize it, then verify if it is build      - 
** correctly.
** The verification is only made in the end of the parsing to let ft_gnl finish-
**  the read of the cub file, avoiding the static buffer to retain unecessary  -
** data.
** even when the program had closed due to some error.
** Requires a line and a scene. The line is a string processed by ft_gnl, is   -
** assumed that when the program enters this function is because a serie of    -
** tile id's (0, 1, 2 etc.) were found.
** The scene is a address to a t_scene instance.
*/

void	set_layout(char *line, t_scene *scene, size_t gnl_stts)
{
	static char	*layout;

	if (!layout)
		layout = ft_calloc(1, sizeof(char));
	if (is_layout_pattern(line))
	{
		layout = ft_reallocncat(layout, line);
		layout = ft_reallocncat(layout, "\n");
	}
	else if (!gnl_stts)
	{
		scene->map->layout = ft_split(layout, '\n');
		free(layout);
		layout = NULL;
		set_axes(scene);
		normalize_map(scene);
		if (check_invalid_status(scene))
		{
			scene->status = -1;
			return ;
		}
		scene->status += 8;
	}
}
