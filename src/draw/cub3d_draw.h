/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:35:28 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/28 18:24:44 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Header containing functions to draw the map.
*/

#ifndef CUB3D_DRAW_H
# define CUB3D_DRAW_H

# include <libft.h>
# include <mlx.h>
# include <cub3d_core.h>

# include "./error/cub3d_draw_error.h"
# include "./structs/cub3d_draw_structs.h"

void		print_map(t_world *world);
t_window	*create_window(char **res, const char *title);

#endif
