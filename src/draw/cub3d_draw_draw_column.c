/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_draw_column.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:03:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/09 10:37:19 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Draw a column of pixels starting from the given position till the height be -
** complete.
** Receive a t_img buffer, an array of two integers containing the x and y     -
** reference where the column must start (consider the first index as x and the-
**  second the y), a integer value of height and a serie of color codes to be  -
** pushed to the screen.
** The columns are drawed from it top to its bottom.
*/

void	draw_column(t_img *img, int orgs[2], int hgt, int pxsq[])
{
	int	row;

	row = orgs[1];
	while (row < hgt)
	{
		pixel_put(img, orgs[0], row, pxsq[row]);
		++row;
	}
}
