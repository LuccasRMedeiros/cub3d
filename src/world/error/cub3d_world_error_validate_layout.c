/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_error_validate_layout.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:46:55 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/23 15:52:56 by lrocigno         ###   ########.fr       */
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

static int	walls_at_col(char **layout, size_t col)
{
	int		walls;
	bool	reverse;
	int		i;

	walls = 0;
	reverse = false;
	i = 0;
	while (i >= 0 || !reverse)
	{
		if (layout[i] == NULL)
			reverse = true;
		else if (layout[i][col] == '1')
			walls = 2;
		else if (ft_strhvchr(INNER, layout[i][col])
			&& (walls == 2 || walls == 0))
			--walls;
		else if ((layout[i][col] == ' ' && walls == 1) || (walls < 0))
			return (walls);
		if (reverse)
			--i;
		else
			++i;
	}
	return (walls);
}

static int	walls_at_row(char *layout)
{
	int		walls;
	bool	reverse;
	int		i;

	walls = 0;
	reverse = false;
	i = 0;
	while (i >= 0 || !reverse)
	{
		if (layout[i] == '1')
			walls = 2;
		else if (ft_strhvchr(INNER, layout[i]) && (walls == 2 || walls == 0))
			--walls;
		else if ((layout[i] == ' ' && walls == 1) || (walls < 0))
			return (walls);
		else if (layout[i] == '\0')
			reverse = true;
		if (reverse)
			--i;
		else
			++i;
	}
	return (walls);
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
** are handled by validate_elements.
*/

bool	validate_layout(t_scene *scene)
{
	char	**layout;
	bool	ret;
	size_t	r;
	size_t	c;

	layout = scene->map->layout;
	ret = true;
	r = 0;
	c = 0;
	while (r < scene->map->map_y && ret)
	{
		if (walls_at_row(layout[r]) != 2)
			ret = false;
		++r;
	}
	while (c < scene->map->map_x && ret)
	{
		if (walls_at_col(layout, c) != 2)
			ret = false;
		++c;
	}
	if (!ret)
		error_msg("The map must be surrounded by walls", "map layout");
	return (ret);
}
