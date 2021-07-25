/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_del_tile.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:51:22 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/24 13:14:42 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Destroy a t_tile.
*/

#include "cub3d_structs.h"

void	del_tile(t_tile *del)
{
	del->id = 0;
	del_img(del->wall_no);
	del_img(del->wall_so);
	del_img(del->wall_we);
	del_img(del->wall_ea);
	free(del);
}
