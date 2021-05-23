/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_structs_del_tile.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:51:22 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/22 12:49:50 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Destroy a t_tile.
*/

#include "cub3d_world_structs.h"

void	del_tile(t_tile *del)
{
	char	*holder;

	holder = del->wall_no;
	free(holder);
	holder = del->wall_so;
	free(holder);
	holder = del->wall_we;
	free(holder);
	holder = del->wall_ea;
	free(holder);	
	free(del);
	del->id = 0;
	del->wall_no = NULL;
	del->wall_so = NULL;
	del->wall_we = NULL;
	del->wall_ea = NULL;
}
