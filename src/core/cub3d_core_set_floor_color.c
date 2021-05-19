/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_set_floor_color.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:19:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/19 12:05:46 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Sets the floor color.
** Receives a line and a scene. The line is a string processed by the ft_gnl   -
** and its assumed that when the program enters the function a "F" char can be -
** found in the beging of such line.
** The scene is a address to an t_scene instance.
*/

#include "cub3d_core.h"

void	set_floor_color(char *line, t_scene *scene)
{
	char **rgb;

	rgb = ft_split(line + 1, ' ');
	if (check_invalid_color(rgb, "floor"))
		return ;
	scene->map->floor_color[0] = ft_atoi(rgb[0]);
	scene->map->floor_color[1] = ft_atoi(rgb[1]);
	scene->map->floor_color[2] = ft_atoi(rgb[2]);
	ft_destroyer((void **)rgb);
}
