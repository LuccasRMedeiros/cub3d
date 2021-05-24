/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_set_tileset.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:26:26 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/23 20:10:59 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ABOUT THE FUNCTION ==========================================================
** Set the properties of a tileset. Due to the nature of the project to not use-
**  more than one texture for walls the function sets the id automatically to 1.
** Requires a line and a scene. The line is a string processed by gnl, it is   -
** assumed that when the program enters this function, the line contains one of-
**  the indentifiers for textures.
** "scene" is a address to a initialized t_scene instance.
** Upon a successfully set adds 1 to scene status (per correct face, in the end-
** adds a total of 4 to scene status).
** Case it is the second time passing a texture to a wall side it will call for-
**  double_def and will exit the function.
** =============================================================================
*/

#include "cub3d_world.h"

/*
** double_def is called to auxiliate set_tileset to free the variable "path"   -
** and set "scene->status" as -1 avoiding a memory leak.
*/

static void	double_def(char *path, t_scene *scene)
{
	free(path);
	path = NULL;
	scene->status = -1;
}

void	set_tileset(char *line, t_scene *scene)
{
	char	*path;

	path = ft_strdup(ft_strchr(line, '.'));
	if (!validate_texture(path, "wall texture"))
	{
		free(path);
		path = NULL;
		scene->status = -1;
		return ;
	}
	scene->map->tileset->id = '1';
	if (ft_strncmp(line, "NO", 2) == 0 && !scene->map->tileset->wall_no)
		scene->map->tileset->wall_no = path;
	else if (ft_strncmp(line, "SO", 2) == 0 && !scene->map->tileset->wall_so)
		scene->map->tileset->wall_so = path;
	else if (ft_strncmp(line, "WE", 2) == 0 && !scene->map->tileset->wall_we)
		scene->map->tileset->wall_we = path;
	else if (ft_strncmp(line, "EA", 2) == 0 && !scene->map->tileset->wall_ea)
		scene->map->tileset->wall_ea = path;
	else
	{
		double_def(path, scene);
		return ;
	}
	scene->status += 1;
}
