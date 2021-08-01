/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:17:39 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/31 22:37:15 by lrocigno         ###   ########.fr       */
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

typedef struct s_program
{
	bool			running;
	t_wndw			*wndw;
	t_world			*wrld;
	t_actor			*player;
	t_static_obj	*sprite_list;
}					t_program;

typedef struct s_bmp_h
{
	uint16_t	type;
	uint32_t	size;
	uint16_t	reserved;
	uint32_t	offset;
	uint32_t	hdr_sz;
	int32_t		wdt;
	int32_t		hgt;
	uint16_t	n_planes;
	uint16_t	bpp;
	uint32_t	compression;
	uint32_t	img_sz_b;
	int32_t		res_x;
	int32_t		res_y;
	uint32_t	n_colors;
	uint32_t	i_colors;
}	t_bmp_h;

t_cub	*read_cub(int argc, char **argv);
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
int		close_pressed(t_program *prog);
int		update_frame(t_program *prog);
void	fst_frame(t_program *prog, bool save);
void	screenshot(t_img *f);

#endif
