/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_error_validate_map.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:46:55 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/29 21:57:17 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_world_error.h"

/*
** Both walls_at_col and walls_at_row looks to each index at what it is meant  -
** look at from its beginning to its end and the reverse path also, it will    -
** assign 2 to "walls" var each time it find a wall, if it find a INNER element-
**  (02NSWE) it set walls to 1.
** So each number returned from "walls_at" functions means:
**  - 2: There are walls in both extremes and its interior is filled.
**  - 1: There are no walls surrounding the interiors of the map.
**  - 0: A empty column was found, and like the break lines between the map    -
** layout, they are invalid.
*/

static int	walls_at_col(char **map, size_t col)
{
	int		walls;
	bool	reverse;
	int		i;

	walls = 0;
	reverse = false;
	i = 0;
	while (i >= 0 || !reverse)
	{
		if (map[i] == NULL)
		{
			if (walls != 2)
				return (walls);
			reverse = true;
		}
		else if (map[i][col] == '1')
			walls = 2;
		else if (ft_strhvchr(INNER, map[i][col]))
			walls = 1;
		else if ((map[i][col] == ' ' && walls == 1))
			return (walls);
		if (reverse)
			--i;
		else
			++i;
	}
	return (walls);
}

static int	walls_at_row(char *map)
{
	int		walls;
	bool	reverse;
	int		i;

	walls = 0;
	reverse = false;
	i = 0;
	while (i >= 0 || !reverse)
	{
		if (map[i] == '1')
			walls = 2;
		else if (ft_strhvchr(INNER, map[i]))
			walls = 1;
		else if ((map[i] == ' ' && walls == 1))
			return (walls);
		else if (map[i] == '\0')
			reverse = true;
		if (reverse)
			--i;
		else
			++i;
	}
	return (walls);
}

/*
** Call walls_at_row and walls_at_col to check if there are walls surrounding  -
** the map.
*/

static int	conf_walls(char **map, t_world *world)
{
	int		walls;
	size_t	r;
	size_t	c;
	
	walls = 0;
	r = 0;
	c = 0;
	while (r < world->map_y)
	{
		walls = walls_at_row(map[r]);
		if (walls != 2)
			return (walls);
		++r;
	}
	while (c < world->map_x)
	{
		walls = walls_at_col(map, c);
		if (walls != 2)
			return (walls);
		++c;
	}
	return (walls);
}

/*
** Check if the map is invalid.
** Receives the address for a t_world instance then look into its map member to-
**  see if there are errors.
** Possible errors are:
**  - There is a line break between the map layout;
**  - The map isn't surrounded by walls.
** Case one of the above situations be verified, returns true to sinalize an   -
** error.
** Erros like unknown element ids or more than one player or no player at all  -
** are handled by validate_elements.
*/

bool	validate_map(t_world *world)
{
	char	**map;
	int		cw;

	map = world->map;
	cw = conf_walls(map, world);
	if (cw == 1)
	{
		error_msg("The map must be surrounded by walls", "map layout");
		return (false);
	}
	else if (cw == 0)
	{
		error_msg("Blank column found on map layout", "map layout");
		return (false);
	}
	return (true);
}
