/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_set_tilesheet.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:26:26 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/22 11:33:44 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_core.h"

/*
** set_wall auxiliates set_tilesheet verificating a double definition for a    - 
** given wall (as a char *).
** dst should point to the actual address of a member of tileset, src is the   -
** data to be placed into that member.
** The address to the world instance is used to make possible to set the status-
**  case something went wrong.
*/

static void	set_wall(t_cub *cub, char *path, char *face)
{
	if (!is_first_def(face, "wall texture", 0)
		|| !validate_texture(path, "wall texture"))
	{
		cub->status = -1;
		free(path);
		path = NULL;
		return ;
	}
	face = path;
	cub->status += 1;
}

/*
** Configure a tilesheet.
** First verify which wall face it should set, then call the sub function      -
** set_wall.
*/

void	set_tilesheet(const char *line, t_cub *cub)
{
	char	*path;

	path = ft_strdup(ft_strchr(line, '.'));
	if (!ft_strncmp(line, "NO", 2))
		set_wall(cub, path, cub->tilesheet->no_face);
	else if (!ft_strncmp(line, "SO", 2))
		set_wall(cub, path, cub->tilesheet->so_face);
	else if (!ft_strncmp(line, "WE", 2))
		set_wall(cub, path, cub->tilesheet->we_face);
	else if (!ft_strncmp(line, "EA", 2))
		set_wall(cub, path, cub->tilesheet->ea_face);
}
