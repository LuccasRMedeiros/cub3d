/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_set_scene_resolution.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:27:16 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/17 18:03:49 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Set the t_scene res member.
** Requires a line and a scene. The line is a string processed by ft_gnl, it is-
**  assumed that when the program enters this function a "R" were found on such-
**  line, so it will look only to the values.
** The scene must be an initialized scene address, so set_scene_resolution wii -
** process data for its res member.
** set_scene_resolution doesn't returns any value.
*/

#include "cub3d_core.h"

void	set_scene_resolution(char *line, t_scene *scene)
{
	char	**values;

	values = ft_split(line + 1, ' ');
	if (check_invalid_res(values))
		return ;
	scene->res[0] = ft_atoi(*values);
	++values;
	scene->res[1] = ft_atoi(*values);
	free(values);
}
