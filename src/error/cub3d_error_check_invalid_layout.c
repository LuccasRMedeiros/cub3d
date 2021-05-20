/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error_check_invalid_layout.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:46:55 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/20 18:06:48 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Check if the layout is invalid.
** Receives a const char then look into it to see if there are errors.
** Possible errors are:
**  - There is a line break between the map layout;
**  - The map isn't surrounded by walls.
** Case one of the above situations be verified, returns true to sinalize an   -
** error.
** Erros like unknown element ids or more than one player or no player at all  -
** are handled by check_invalid_elements.
*/

#include "cub3d_error.h"

static bool	no_wall_at_pos(const char *line, size_t n_ln, size_t ttl)
{
	size_t	i;
	size_t	cnt_w;

	i = 0;
	cnt_w = 0;
	while (line[i] != '\0')
	{
		if ((n_ln == 0 || n_ln == ttl) && ft_strhvchr("02NSWE", line[i]))
			return (true);
		if (line[i] == '1' && (n_ln > 0 && n_ln < ttl))
		{
			if (cnt_w == 0)
				++cnt_w;
			else if (line[i + 1] == ' ' || line[i + 1] == '\n'
				|| line [i + 1] == '\0')
				++cnt_w;
			else if (cnt_w == 2)
				cnt_w = 1;
		}
		++i;
	}
	if (cnt_w != 2 && (n_ln > 0 && n_ln < ttl))
		return (true);
	return (false);
}

static bool	no_wall(const char *layout)
{
	char	**check;
	size_t	ttl;
	size_t	c;

	check = ft_split(layout, '\n');
	ttl = ft_strstrlen(check);
	c = 0;
	while (check[c] != NULL)
	{
		if (no_wall_at_pos(check[c], c, ttl))
			return (true);
		++c;
	}
	ft_destroyer((void **)check);
	return (false);
}

bool	check_invalid_layout(const char *layout)
{
	size_t	i;
	char	last;

	i = 0;
	last = layout[i];
	while (layout[i] != '\0')
	{
		if ((last == ' ' || last == '\n') && layout[i] == '\n')
		{
			error_msg("Break line between map layout", "map layout");
			return (true);
		}
		last = layout[i];
		++i;
	}
	if (no_wall(layout))
	{
		error_msg("The map must be surrounded by walls", "map layout");
		return (true);
	}
	return (false);
}
