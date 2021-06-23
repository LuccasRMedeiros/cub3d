/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_cub.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:39:09 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/23 18:36:32 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Creates a t_cub instance.
** A t_cub is a buffer the program holds in the early stages of execution. It  -
** keeps information retrived by the informed cub file.
*/

t_cub	*new_cub(void)
{
	t_cub	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->status = 0;
	new->res = {-1, -1};
	new->tilesheet = new_sheet('1', true);
    new->spritesheet = new_sheet('2', false);
    new->floor_color = {-1, -1, -1};
    new->ceilling_color = {-1, -1, -1};
	new->pre_layout = ft_calloc(1, sizeof(char));
    new->layout = NULL;
    new->map_axis = {0, 0};
    new->player_pos = {0, 0};
	return (new);
}
