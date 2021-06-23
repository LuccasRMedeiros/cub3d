/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:17:39 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/23 16:22:40 by lrocigno         ###   ########.fr       */
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
# include <cub3d_draw.h>
# include <cub3d_world.h>

# include "./error/cub3d_core_error.h"
# include "./structs/cub3d_core_structs.h"

t_cub	*read_cub(char *cub_path);
void	set_res(const char *line, t_cub *cub);
void	set_tilesheet(const char *line, t_cub *cub);
void	set_spritesheet(const char *line, t_cub *cub);
void	set_floor_color(const char *line, t_cub *cub);
void	set_ceilling_color(const char *line, t_cub *cub);
void	set_map(const char *line, t_cub *cub, size_t gnl_stts);
int		close_program(t_world *world);
int		key_pressed(int key, t_world *world);
int		key_released(int key, t_window *window);

#endif
