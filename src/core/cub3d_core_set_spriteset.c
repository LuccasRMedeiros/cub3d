/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_set_spriteset.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:04:03 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/17 18:34:38 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Set the texture for the map sprite. Due to the nature of the project to have-
**  only one sprite per map and such sprite only having one direction, the     -
** function automatically sets the id to 2 and only expect for on texture.
** Requires a line and a scene. The line is a string processed by the gnl, it  -
** is assumed that the first content of such line is a "S" char.
** "scene" is a address to a initialized t_scene instance.
*/

#include "cub3d_core.h"

void	set_spriteset(char *line, t_scene *scene)
{
	char	*path;

	path = ft_strdup(ft_strchr(line, '.'));
	if (check_invalid_texture(path))
	{
		path = NULL;
		free(path);
		return ;
	}
	scene->map->spriteset->sprite = path;
}
