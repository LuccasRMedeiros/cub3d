/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_del_tile.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:51:22 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/27 11:04:29 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Destroy a t_tile.
*/

#include "cub3d_structs.h"

void	del_tile(t_tile *del)
{
	del->id = 0;
	free(del->wall_no);
	del->wall_no = NULL;
	free(del->wall_so);
	del->wall_so = NULL;
	free(del->wall_we);
	del->wall_we = NULL;
	free(del->wall_ea);
	del->wall_ea = NULL;
	free(del);
}
