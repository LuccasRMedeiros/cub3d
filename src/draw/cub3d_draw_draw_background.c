/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_draw_background.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:55:42 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/01 15:09:23 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Receive a t_world instance, then using its floor and ceilling colors, draws -
** the background, that is, the lower session of the entire screen will be     -
** painted with the floor color, the upper, will have the ceilling.
*/

#include "cub3d_draw.h"

void	draw_background(t_world *world)
{
	t_window	*wndw;

	wndw = get_window(NULL);
	wndw->bg[0] = mlx_new_image(wndw->con_ptr, wndw->wdt, wndw->hgt / 2);
	wndw->bg[1] = mlx_new_image(wndw->con_ptr, wndw->wdt, wndw->hgt / 2);
