/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_set_ceilling_color.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:47:06 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/24 11:09:32 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_core.h"

/*
** Sets the ceilling color.
** Receives a line and a world. The line is a string processed by the ft_gnl   -
** and its assumed that when the program enters the function a "C" char can be -
** found in the beging of such line.
** The world is a address to an t_world instance.
*/

void	set_ceilling_color(const char *line, t_cub *cub)
{
	char	**rgb;

	rgb = ft_split(line + 1, ',');
	if (!validate_color(rgb, "ceilling")
		|| !is_first_def(&cub->ceilling_color[0], "Ceilling color", -1))
	{
		cub->status = -1;
		return ;
	}
	cub->ceilling_color[0] = ft_atoi(rgb[0]);
	cub->ceilling_color[1] = ft_atoi(rgb[1]);
	cub->ceilling_color[2] = ft_atoi(rgb[2]);
	cub->status += 1;
	ft_destroyer((void **)rgb);
}
