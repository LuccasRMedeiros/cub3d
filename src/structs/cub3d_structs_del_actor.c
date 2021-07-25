/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_del_actor.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 22:10:59 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/25 02:07:04 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
**	Delete a t_actor instance.
*/

void	del_actor(t_actor *del)
{
	del->id = 0;
	del->map_x = 0;
	del->map_y = 0;
	del->abs_x = 0;
	del->abs_y = 0;
	del->dir = 0;
	del->delta_x = 0;
	del->delta_xl = 0;
	del->delta_y = 0;
	del->delta_yl = 0;
	free(del);
}
