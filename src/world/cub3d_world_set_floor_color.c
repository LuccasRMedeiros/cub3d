/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_set_floor_color.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:19:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/29 21:20:29 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Sets the floor color.
** Receives a line and a world. The line is a string processed by the ft_gnl   -
** and its assumed that when the program enters the function a "F" char can be -
** found in the beging of such line.
** The world is a address to an t_world instance.
*/

#include "cub3d_world.h"

void	set_floor_color(const char *line, t_world *world)
{
	char	**rgb;

	rgb = ft_split(line + 1, ',');
	if (!validate_color(rgb, "floor")
		|| !is_first_def(&world->ceilling_color[0], "F"))
	{
		world->status = -1;
		return ;
	}
	world->floor_color[0] = ft_atoi(rgb[0]);
	world->floor_color[1] = ft_atoi(rgb[1]);
	world->floor_color[2] = ft_atoi(rgb[2]);
	world->status += 1;
	ft_destroyer((void **)rgb);
}
