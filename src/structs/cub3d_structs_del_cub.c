/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_del_cub.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:11:21 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/27 14:32:38 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Delete a cub instance.
*/

void	del_cub(t_cub *del)
{
	del->status = 0;
	del->res[0] = 0;
	del->res[1] = 0;
	del->tilesheet = NULL;
	del_sheet(del->spritesheet);
	del->spritesheet = NULL;
	del->f_color[0] = -1;
	del->f_color[1] = -1;
	del->f_color[2] = -1;
	del->c_color[0] = -1;
	del->c_color[1] = -1;
	del->c_color[2] = -1;
	free(del->pre_layout);
	del->pre_layout = NULL;
	ft_destroyer((void **)del->layout);
	del->layout = NULL;
	del->map_axis[0] = 0;
	del->map_axis[1] = 0;
	del->player_pos[0] = 0;
	del->player_pos[1] = 0;
	free(del);
}
