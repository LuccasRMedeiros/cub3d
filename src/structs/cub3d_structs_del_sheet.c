/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_del_sheet.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:41:17 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/23 18:35:50 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Deletes a t_tilesheet instance.
*/

void	del_tilesheet(t_tilesheet *del)
{
	del->is_wall = false;
	del->wall_no = NULL;
	del->wall_so = NULL;
	del->wall_we = NULL;
	del->wall_ea = NULL;
	free(del);
}
