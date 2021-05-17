/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_new_scene.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:22:28 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/16 16:09:58 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Initialize a new scene.
*/

#include "cub3d_core.h"

t_scene	*new_scene(void)
{
	t_scene	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->r_width = 0;
	new->r_height = 0;
	new->floor_color[] = {0, 0, 0};
	new->ceilling_color[] = {0, 0, 0};
	new->map = new_map();
