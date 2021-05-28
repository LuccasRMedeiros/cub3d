/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_set_tileset.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:26:26 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/28 19:08:38 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_world.h"

/*
** set_wall auxiliates set_tileset to verificate a double definition for a     - 
** given wall (as a char *).
** dst should point to the actual address of a member of tileset, src is the   -
** data to be placed into that member.
** The address to the world instance is used to make possible to set the status-
** case something went wrong.
*/

static void	set_wall(char *wall, char *path, t_world *world)
{
	if (!is_first_def(wall, "wall texture")
	|| !validate_texture(path, "wall texture"))
	{
		world->status = -1;
		free(path);
		path = NULL;
		return ;
	}
	wall = path;
	world->status += 1;
}

/*
** Set the properties of a tileset. Due to the nature of the project to not use-
**  more than one texture for walls the function sets the id automatically to 1.
** Requires a line and a world. The line is a string processed by gnl, it is   -
** assumed that when the program enters this function, the line contains one of-
**  the indentifiers for textures.
** "world" is a address to a initialized t_world instance.
** Upon a successfully set adds 1 to world status (per correct face, in the end-
** adds a total of 4 to world status).
** Case it is the second time passing a texture to a wall side it will call for-
**  double_def and will exit the function.
*/

void	set_tileset(const char *line, t_world *world)
{
	char	*path;

	path = ft_strdup(ft_strchr(line, '.'));
	world->tileset->id = '1';
	if (!ft_strncmp(line, "NO", 2))
		set_wall(world->tileset->wall_no, path, world);
	else if (!ft_strncmp(line, "SO", 2))
		set_wall(world->tileset->wall_so, path, world);
	else if (!ft_strncmp(line, "WE", 2))
		set_wall(world->tileset->wall_we, path, world);
	else if (!ft_strncmp(line, "EA", 2))
		set_wall(world->tileset->wall_ea, path, world);
}
