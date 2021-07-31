/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_normalize_angle.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 00:01:02 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/29 13:23:14 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Attempt to regulate the value of angle keeping it more than zero and less   -
** than 2PI (aka EAST).
*/

float	normalize_angle(float ang)
{
	while (ang >= EAST)
		ang -= EAST;
	while (ang < 0)
		ang += EAST;
	return (ang);
}
