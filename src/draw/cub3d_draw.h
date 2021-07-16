/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:35:28 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/15 15:43:53 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Header containing functions to draw the map.
*/

#ifndef CUB3D_DRAW_H
# define CUB3D_DRAW_H

# include <cub3d_structs.h>

void	pixel_put(t_img *img, int posx, int posy, int color);
void	draw_column(t_img *img, int pos[2], int hgt, int pxsq[]);
void	update_frame(t_wndw *wndw, t_world *wrld);
void	ray_cast(t_world *wrld, t_actor *player);
t_ray	h_cast_ray(t_actor *player, t_world *wrld, double ang);
t_ray	v_cast_ray(t_actor *player, t_world *wrld, double ang);

#endif
