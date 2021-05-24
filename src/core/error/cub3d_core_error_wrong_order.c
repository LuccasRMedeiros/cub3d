/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_error_wrong_order.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:39:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/23 20:58:45 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function must be called everytime a misplaced layout is found on the   -
** cub file. In other words, the world properties were not defined yet and a   -
** layout pattern is placed before they be setted.
** Its prototype is void cause it should not return anything, just set the     -
** scene->status as -1 and emit an error message.
** Requires an address to a t_scene instance.
*/

#include "cub3d_core_error.h"

void	wrong_order(t_scene *scene)
{
	scene->status = -1;
	error_msg ("The maṕ layout begins before all the properties are setted",
		"cub file");
}
