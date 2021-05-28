/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 11:44:11 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/28 19:08:33 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Header with the difinitions and prototypes for world pre-building functions.
*/

#ifndef CUB3D_WORLD_H
# define CUB3D_WORLD_H

# include <libft.h>

# include "./structs/cub3d_world_structs.h"
# include "./error/cub3d_world_error.h"

# define ELEMENTS "012NSWE"

void	set_world_resolution(const char *line, t_world *world);
void	set_tileset(const char *line, t_world *world);
void	set_spriteset(const char *line, t_world *world);
void	set_floor_color(const char *line, t_world *world);
void	set_ceilling_color(const char *line, t_world *world);
void	set_map(const char *line, t_world *world, size_t gnl_stts);

#endif
