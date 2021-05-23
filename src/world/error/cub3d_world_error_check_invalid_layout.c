/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_error_check_invalid_layout.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:46:55 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/22 21:43:38 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_world_error.h"

/*
** Both walls_at_col and walls_at_row looks to each index at what it is meant  -
** look at from its beginning to its end and the reverse path also, it will    -
** assign 2 to "walls" var each time it find a wall, if it find a INNER element-
**  (02NSWE) it reduces 1 from "walls" value, but only when "walls" value is 2 -
** or 0.
*/

static int walls_at_col(const char **layout, size_t col)
{
	int		walls;
	bool	reverse;
	size_t	i;

	walls = 0;
	reverse = false;
	i = 0;
	while (i > 0 || !reverse)
	{
		if (layout[i][col] == '1')
			walls = 2;
		else if (ft_strhvchr(INNER, layout[i][col]) &&
			(walls == 2 || walls == 0))
			--walls;
		if ((layout[i][col] == ' ' && walls == 1) || (walls < 0))
			return (walls);
		if (reverse)
			--i;
		else
			++i;
		if (layout[i][col] == '\0')
			reverse = true;
	}
	return (walls);
}

static int walls_at_row(const char *layout)
{
	int		walls;
	bool	reverse;
	size_t	i;

	walls = 0;
	reverse = false;
	i = 0;
	while (i > 0 || !reverse)
	{
		if (layout[i] == '1')
			walls = 2;
		else if (ft_strhvchr(INNER, layout[i]) && (walls == 2 || walls == 0))
			--walls;
		if ((layout[i] == ' ' && walls == 1) || (walls < 0))
			return (walls);
		if (reverse)
			--i;
		else
			++i;
		if (layout[i] == '\0')
			reverse = true;
	}
	return (walls);
}

/*
** no_wall calls for walls_at_row and walls_at_col, if it receive a value      -
** diferent from 0 it understands that the layout may have problems.
*/

static bool	no_wall(t_scene *scene)
{
	char	**layout;
	size_t	r;
	size_t	c;

	layout = scene->map->layout;
	r = 0;
	c = 0;
	while (r <= scene->map->map_x || c <= scene->map->map_y)
	{
		if (r <= scene->map->map_x)
		{
			if (walls_at_row(check[r]) != 2)
				return (true);
			++r;
		}
		if (c <= scene->map->map_y)
		{
			if (walls_at_col(check, c) != 2)
				return (true);
			++c;
		}
	}
	return (false);
}

/*
** Check if the layout is invalid.
** Receives the address for a t_scene instance then look into its layout member-
**  to see if there are errors.
** Possible errors are:
**  - There is a line break between the map layout;
**  - The map isn't surrounded by walls.
** Case one of the above situations be verified, returns true to sinalize an   -
** error.
** Erros like unknown element ids or more than one player or no player at all  -
** are handled by check_invalid_elements.
*/

int	check_invalid_layout(t_scene *scene)
{
	size_t	i;
	char	last;

	i = 0;
	if (no_wall)
	{
		error_msg("The map must be surrounded by walls", "map layout");
		return (-1);
	}
	return (8);
}
