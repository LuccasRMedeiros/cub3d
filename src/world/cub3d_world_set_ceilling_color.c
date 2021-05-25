/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_set_ceilling_color.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:47:06 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/25 11:00:42 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Sets the ceilling color.
** Receives a line and a world. The line is a string processed by the ft_gnl   -
** and its assumed that when the program enters the function a "C" char can be -
** found in the beging of such line.
** The world is a address to an t_world instance.
*/

#include "cub3d_world.h"

void	set_ceilling_color(char *line, t_world *world)
{
	char	**rgb;

	rgb = ft_split(line + 1, ' ');
	if (!validate_color(rgb, "ceilling")
		|| !is_first_definition(&world->map->ceilling_color[0], "C"))
	{
		world->status = -1;
		return ;
	}
	world->map->ceilling_color[0] = ft_atoi(rgb[0]);
	world->map->ceilling_color[1] = ft_atoi(rgb[1]);
	world->map->ceilling_color[2] = ft_atoi(rgb[2]);
	world->status += 1;
	ft_destroyer((void **)rgb);
}
