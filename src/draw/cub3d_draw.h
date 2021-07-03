/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:35:28 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/03 20:00:22 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Header containing functions to draw the map.
*/

#ifndef CUB3D_DRAW_H
# define CUB3D_DRAW_H

# include <cub3d_structs.h>

# define PLAYER "NSWE"

void	pixel_put(t_img *img, int posx, int posy, int color);
void	draw_image(t_wndw *wndw, char *el, int org_x, int org_y);
void	draw_map(t_world *wrld, t_wndw *wndw);
void	draw_player(t_wndw *wndw, t_world *wrld);
int		shift_to_color(int r, int g, int b);

#endif
