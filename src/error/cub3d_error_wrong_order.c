/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error_wrong_order.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:39:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/23 19:17:36 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function must be called everytime a misplaced layout is found on the   -
** cub file. In other words, the world properties were not defined yet and a   -
** layout pattern is placed before they be setted.
** Its prototype is void cause it should not return anything, just set the     -
** world->status as -1 and emit an error message.
** Requires an address to a t_world instance.
*/

#include "cub3d_error.h"

void	wrong_order(t_cub *cub)
{
	cub->status = -1;
	if (cub->layout)
	{
		error_msg("Line break between map layout", "map layout");
		return ;
	}
	error_msg ("The map layout begins before all the properties are setted",
		"cub file");
}
