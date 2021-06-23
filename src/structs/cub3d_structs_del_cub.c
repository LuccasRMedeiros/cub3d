/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_del_cub.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:11:21 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/23 18:35:50 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Delete a cub instance.
*/

void	del_cub(t_cub *del)
{
	free(del->pre_layout);
	ft_destroyer(del->layout);
	del->status = 0;
	del->res = {-1, -1};
	del_sheet(del->tilesheet);
	del_sheet(del->spritesheet);
	del->floor_color = {-1, -1, -1};
	del->ceilling_color = {-1, -1, -1};
	del->map_axis = {0, 0, 0};
	del->player_pos = {0, 0, 0};
}
