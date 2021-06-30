/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:35:28 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/27 13:47:59 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Header containing functions to draw the map.
*/

#ifndef CUB3D_DRAW_H
# define CUB3D_DRAW_H

# include <cub3d_structs.h>

void	pixel_put(t_img *img, int posx, int posy, int color);
void	draw_image(t_img *img, int org_x, int org_y);
void	print_map(t_world *world, t_img *screen);
int		shift_to_color(int r, int g, int b);

#endif
