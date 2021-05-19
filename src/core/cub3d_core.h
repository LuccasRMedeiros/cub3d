/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:17:39 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/19 20:18:27 by lrocigno         ###   ########.fr       */
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
# include <cub3d_error.h>

# include "./structs/cub3d_core_structs.h" // Subheader of core structs.

# define ELEMENTS "012NSWE"

t_scene		*read_cub(char *cub_path);
void	set_scene_resolution(char *line, t_scene *scene);
void	set_tileset(char *line, t_scene *scene);
void	set_spriteset(char *line, t_scene *scene);
void	set_floor_color(char *line, t_scene *scene);
void	set_ceilling_color(char *line, t_scene *scene);
void	set_layout(char *line, t_scene *scene, size_t gnl_stts);

#endif
