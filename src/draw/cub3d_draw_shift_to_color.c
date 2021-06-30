/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_shift_to_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 11:09:21 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/27 11:18:55 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Receive three ints, each corresponding to a primary screen color (red green -
** blue).
** It will then bitshift those values, for red it make 16 left shifts, for     -
** green 8 and dont shift blue.
** The result will be an int that corresponds to a color value.
*/

int	shift_to_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
