/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_set_spritesheet.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:04:03 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/24 11:13:38 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_core.h"

/*
** Set the texture for the map sprite. Due to the nature of the project to have-
**  only one sprite per map and such sprite only having one direction, the     -
** function automatically sets the id to 2 and only expect for on texture.
** Requires a line and a world. The line is a string processed by the gnl, it  -
** is assumed that the first content of such line is a "S" char.
** "world" is a address to a initialized t_world instance.
** Upon a successfully set adds 2 to world status.
*/

void	set_spritesheet(const char *line, t_cub *cub)
{
	char	*path;

	path = ft_strdup(ft_strchr(line, '.'));
	if (!validate_texture(path, "sprite texture")
		|| !is_first_def(cub->spritesheet->no_face, "sprite texture", 0))
	{
		free(path);
		path = NULL;
		cub->status = -1;
		return ;
	}
	cub->spritesheet->no_face = path;
	cub->status += 2;
}
