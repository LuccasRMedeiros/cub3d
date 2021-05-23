/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_set_tileset.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:26:26 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/22 12:14:27 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Set the properties of a tileset. Due to the nature of the project to not use-
**  more than one texture for walls the function sets the id automatically to 1.
** Requires a line and a scene. The line is a string processed by gnl, it is   -
** assumed that when the program enters this function, the line contains one of-
**  the indentifiers for textures.
** "scene" is a address to a initialized t_scene instance.
** Upon a successfully set adds 1 to scene status (per correct face, in the end-
** adds a total of 4 to scene status).
*/

#include "cub3d_world.h"

void	set_tileset(char *line, t_scene *scene)
{
	char	*path;

	path = ft_strdup(ft_strchr(line, '.'));
	if (check_invalid_texture(path, "Wall texture"))
	{
		free(path);
		path = NULL;
		scene->status = -1;
		return ;
	}
	if (ft_strncmp(line, "NO", 2) == 0)
		scene->map->tileset->wall_no = path;
	else if (ft_strncmp(line, "SO", 2) == 0)
		scene->map->tileset->wall_so = path;
	else if (ft_strncmp(line, "WE", 2) == 0)
		scene->map->tileset->wall_we = path;
	else if (ft_strncmp(line, "EA", 2) == 0)
		scene->map->tileset->wall_ea = path;
	scene->status += 1;
}
