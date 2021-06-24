/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_set_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:59:44 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/24 11:23:30 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_core.h"

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

static void	normalize_map(t_cub *cub)
{
	char	**map;
	char	*fill;
	int		l;
	int		lsz;

	map = cub->layout;
	l = 0;
	while (l < cub->map_axis[1])
	{
		lsz = ft_strlen(map[l]);
		if (lsz < cub->map_axis[0])
		{
			lsz = (cub->map_axis[0] - lsz) + 1;
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

static void	set_axes(t_cub *cub)
{
	char	**map;
	int		x;
	int		y;

	map = cub->layout;
	x = 0;
	y = ft_strstrlen(map);
	cub->map_axis[1] = y;
	while (y > 0)
	{
		x = ft_strlen(map[y]);
		if (x > cub->map_axis[0])
			cub->map_axis[0] = x;
		--y;
	}
}

/*
** Set the map, the axes, normalize it, then verify if it is build correctly.
** The verification is only made in the end of the parsing to let ft_gnl finish-
**  the read of the cub file, avoiding the static buffer to retain unecessary  -
** data.
** even when the program had closed due to some error.
** Requires a line and a world. The line is a string processed by ft_gnl, is   -
** assumed that when the program enters this function is because a serie of    -
** elements (0, 1, 2 etc.) were found.
** The world is a address to a t_world instance.
*/

void	set_map(const char *line, t_cub *cub, size_t gnl_stts)
{
	char	*pre_layout;

	pre_layout = cub->pre_layout;
	if (gnl_stts && is_map_pattern(line))
	{
		pre_layout = ft_reallocncat(pre_layout, line);
		pre_layout = ft_reallocncat(pre_layout, "\n");
	}
	else if (!gnl_stts || *pre_layout)
	{
		cub->layout = ft_split(pre_layout, '\n');
		set_axes(cub);
		normalize_map(cub);
		if (!validate_map(cub))
		{
			cub->status = -1;
			return ;
		}
		cub->status += 12;
		set_player(cub);
	}
}
