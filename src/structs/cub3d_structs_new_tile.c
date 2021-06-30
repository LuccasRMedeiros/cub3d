/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_tile.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:36:01 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/27 11:04:29 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Initialize a new t_tile structure.
*/

#include "cub3d_structs.h"

t_tile	*new_tile(t_sheet *tilesheet)
{
	t_tile	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->id = tilesheet->id;
	new->wall_no = ft_strdup(tilesheet->no_face);
	new->wall_so = ft_strdup(tilesheet->so_face);
	new->wall_we = ft_strdup(tilesheet->we_face);
	new->wall_ea = ft_strdup(tilesheet->ea_face);
	return (new);
}
