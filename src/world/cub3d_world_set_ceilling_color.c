/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_set_ceilling_color.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:47:06 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/23 20:10:59 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Sets the ceilling color.
** Receives a line and a scene. The line is a string processed by the ft_gnl   -
** and its assumed that when the program enters the function a "C" char can be -
** found in the beging of such line.
** The scene is a address to an t_scene instance.
*/

#include "cub3d_world.h"

void	set_ceilling_color(char *line, t_scene *scene)
{
	char	**rgb;

	rgb = ft_split(line + 1, ' ');
	if (!validate_color(rgb, "ceilling")
		|| !is_first_definition(scene->map->ceilling_color[0], "C"))
	{
		scene->status = -1;
		return ;
	}
	scene->map->ceilling_color[0] = ft_atoi(rgb[0]);
	scene->map->ceilling_color[1] = ft_atoi(rgb[1]);
	scene->map->ceilling_color[2] = ft_atoi(rgb[2]);
	scene->status += 1;
	ft_destroyer((void **)rgb);
}
