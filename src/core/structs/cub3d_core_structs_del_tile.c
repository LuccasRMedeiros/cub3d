/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_del_tile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:51:22 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/19 11:32:58 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Destroy a t_tile.
*/

#include "cub3d_core_structs.h"

void	del_tile(t_tile *del)
{
	del->id = 0;
	del->wall_no = NULL;
	del->wall_so = NULL;
	del->wall_we = NULL;
	del->wall_ea = NULL;
	free(del);
}
