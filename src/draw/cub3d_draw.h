/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:35:28 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/31 17:53:18 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Header containing functions to draw the map.
 */
#ifndef CUB3D_DRAW_H
#define CUB3D_DRAW_H

#include "cub3d_structs.h"

void pixel_put(st_img *f, int posx, int posy, int color);
void render_projection(st_img *f, st_world *wrld, st_wndw *wndw, st_actor *p);
void render_sprites(st_img *f, st_static_obj *spt_lst, int n_spts);
void ray_cast(st_world *wrld, st_actor *player, int n_rays);
st_ray h_cast_ray(st_actor *player, st_world *wrld, float ang);
st_ray v_cast_ray(st_actor *player, st_world *wrld, float ang);
void print_map(st_world *wrld, st_actor *player, int n_rays);
void draw_background(st_img *bg, st_wndw *wndw, st_world *wrld);
int get_color(st_img *texture, int hgt, int ox, int tx_row);

#endif
