/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_set_layout.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:59:44 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/20 17:15:37 by lrocigno         ###   ########.fr       */
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
		if (check_invalid_layout(layout))
		{
			scene->status = -1;
			return ;
		}
		scene->map->layout = ft_split(layout, '\n');
		layout = NULL;
		free(layout);
		scene->status += 8;
	}	
}
