/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_set_spriteset.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:04:03 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/23 12:39:50 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Set the texture for the map sprite. Due to the nature of the project to have-
**  only one sprite per map and such sprite only having one direction, the     -
** function automatically sets the id to 2 and only expect for on texture.
** Requires a line and a scene. The line is a string processed by the gnl, it  -
** is assumed that the first content of such line is a "S" char.
** "scene" is a address to a initialized t_scene instance.
** Upon a successfully set adds 2 to scene status.
*/

#include "cub3d_world.h"

void	set_spriteset(char *line, t_scene *scene)
{
	char	*path;

	path = ft_strdup(ft_strchr(line, '.'));
	if (!validate_texture(path, "sprite texture"))
	{
		free(path);
		path = NULL;
		return ;
	}
	scene->map->spriteset->sprite = path;
	scene->status += 2;
}
