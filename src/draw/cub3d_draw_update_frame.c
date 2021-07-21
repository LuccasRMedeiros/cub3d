/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_update_frame.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:51:56 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/21 02:25:33 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Ask to ray_caster cast rays from the plaer postion then loop through the ray-
**  array and call draw_column to draw each column correspondent to each ray.
*/

void	update_frame(t_wndw *wndw, t_world *wrld, t_actor *p)
{
	ray_cast(wrld, p);
	render_projection(wndw, p);
	//print_map(wrld, p);
}
