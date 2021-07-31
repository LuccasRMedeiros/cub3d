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

/*
** Header containing functions to draw the map.
*/

#ifndef CUB3D_DRAW_H
# define CUB3D_DRAW_H

# include <cub3d_structs.h>

void	pixel_put(t_img *f, int posx, int posy, int color);
void	render_projection(t_img *f, t_world *wrld, t_wndw *wndw, t_actor *p);
void	render_sprites(t_img *f, t_static_obj *spt_lst, int n_spts);
void	ray_cast(t_world *wrld, t_actor *player, int n_rays);
t_ray	h_cast_ray(t_actor *player, t_world *wrld, float ang);
t_ray	v_cast_ray(t_actor *player, t_world *wrld, float ang);
void	print_map(t_world *wrld, t_actor *player, int n_rays);
void	draw_background(t_img *bg, t_wndw *wndw, t_world *wrld);
int		get_color(t_img *texture, int hgt, int ox, int tx_row);

#endif
