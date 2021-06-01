/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:17:39 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/31 17:34:10 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Header containing all the core functions of cub3D.
*/

#ifndef CUB3D_CORE_H
# define CUB3D_CORE_H

# include <libft.h>
# include <math.h>
# include <stdio.h>
# include <mlx.h>
# include <cub3d_world.h>
# include <cub3d_error.h>
# include <cub3d_draw.h>

# include "./error/cub3d_core_error.h"

t_world		*read_cub(char *cub_path);
t_window	*ret_window(char *line);
int			close_window(t_world *world);
int			key_pressed(int key, t_world *world);
int			key_released(int key, t_window *window);

#endif
