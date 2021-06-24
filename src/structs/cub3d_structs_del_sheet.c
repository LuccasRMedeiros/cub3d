/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_del_sheet.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:41:17 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/24 13:06:30 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Deletes a t_tilesheet instance.
*/

void	del_sheet(t_sheet *del)
{
	del->is_wall = false;
	del->no_face = NULL;
	del->so_face = NULL;
	del->we_face = NULL;
	del->ea_face = NULL;
	free(del);
}
