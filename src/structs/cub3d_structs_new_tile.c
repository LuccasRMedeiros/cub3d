/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_tile.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:36:01 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/31 18:15:55 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Initialize a new t_tile structure.
*/

#include "cub3d_structs.h"

t_tile	*new_tile(t_sheet *tilesheet, t_wndw *wndw)
{
	t_tile	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->id = tilesheet->id;
	new->wall_no = new_img(wndw, 0, 0, tilesheet->no_face);
	new->wall_so = new_img(wndw, 0, 0, tilesheet->so_face);
	new->wall_we = new_img(wndw, 0, 0, tilesheet->we_face);
	new->wall_ea = new_img(wndw, 0, 0, tilesheet->ea_face);
	return (new);
}
