/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_del_sheet.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:41:17 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/04 20:37:07 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Deletes a t_tilesheet instance.
*/

void	del_sheet(t_sheet *del)
{
	del->id = 0;
	del->is_wall = false;
	if (del->no_face)
		free(del->no_face);
	if (del->so_face)
		free(del->so_face);
	if (del->we_face)
		free(del->we_face);
	if (del->ea_face)
		free(del->ea_face);
	del->no_face = NULL;
	del->so_face = NULL;
	del->we_face = NULL;
	del->ea_face = NULL;
	free(del);
}
