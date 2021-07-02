/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:35:28 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/01 21:20:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Header containing functions to draw the map.
*/

#ifndef CUB3D_DRAW_H
# define CUB3D_DRAW_H

# include <cub3d_structs.h>

void	pixel_put(t_img *img, int posx, int posy, int color);
void	draw_image(t_wndw *wndw, int org_x, int org_y);
void	print_map(t_world *wrld, t_wndw *wndw);
int		shift_to_color(int r, int g, int b);

#endif
