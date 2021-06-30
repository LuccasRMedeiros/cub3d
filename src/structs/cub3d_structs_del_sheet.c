/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_del_sheet.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:41:17 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/25 14:25:33 by lrocigno         ###   ########.fr       */
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
	free(del->no_face);
	del->no_face = NULL;
	free(del->so_face);
	del->so_face = NULL;
	free(del->we_face);
	del->we_face = NULL;
	free(del->ea_face);
	del->ea_face = NULL;
	free(del);
}
