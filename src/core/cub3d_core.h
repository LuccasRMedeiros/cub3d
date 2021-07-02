/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:17:39 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/01 18:54:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Header containing all the core functions of cub3D.
*/

#ifndef CUB3D_CORE_H
# define CUB3D_CORE_H

# include <cub3d_draw.h>
# include <cub3d_error.h>
# include <cub3d_structs.h>
# include <cub3d_world.h>

typedef struct	s_program
{
	t_wndw	*wndw;
	t_world	*wrld;
}	t_program;

t_cub	*read_cub(char *cub_path);
void	set_res(const char *line, t_cub *cub);
void	set_tilesheet(const char *line, t_cub *cub);
void	set_spritesheet(const char *line, t_cub *cub);
void	set_floor_color(const char *line, t_cub *cub);
void	set_ceilling_color(const char *line, t_cub *cub);
void	set_map(const char *line, t_cub *cub, size_t gnl_stts);
void	set_player(t_cub *cub);
int		close_program(t_program *prog);
int		key_pressed(int key, t_program *prog);
int		key_released(int key, t_program *prog);

#endif
