/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_del_cub.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:11:21 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/24 13:05:10 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Delete a cub instance.
*/

void	del_cub(t_cub *del)
{
	free(del->pre_layout);
	ft_destroyer((void **)del->layout);
	del->status = 0;
	del->res[0] = 0;
	del->res[1] = 0;
	del_sheet(del->tilesheet);
	del_sheet(del->spritesheet);
	del->floor_color[0] = -1;
	del->floor_color[1] = -1;
	del->floor_color[2] = -1;
	del->ceilling_color[0] = -1;
	del->ceilling_color[1] = -1;
	del->ceilling_color[2] = -1;
	del->map_axis[0] = 0;
	del->map_axis[1] = 0;
	del->player_pos[0] = 0;
	del->player_pos[1] = 0;
	free(del);
}
