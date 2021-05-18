/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_set_ceilling_color.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:47:06 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/17 22:48:22 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
** Sets the ceilling color.
** Receives a line and a scene. The line is a string processed by the ft_gnl   -
** and its assumed that when the program enters the function a "F" char can be -
** found in the beging of such line.
** The scene is a address to an t_scene instance.
*/

#include "cub3d_core.h"

void	set_ceilling_color(char *line, t_scene *scene)
{
	char **rgb;

	rgb = ft_split(line + 1, ' ');
	if (check_invalid_color(rgb, "floor"))
		return ;
	scene->map->ceilling[0] = ft_atoi(rgb[0]);
	scene->map->ceilling[1] = ft_atoi(rgb[1]);
	scene->map->ceilling[2] = ft_atoi(rgb[2]);
	ft_destroyer(rgb);
}
