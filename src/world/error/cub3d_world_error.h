/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_error.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 15:06:13 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/25 10:58:38 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Header for validation on world creation.
*/

#ifndef CUB3D_WORLD_ERROR_H
# define CUB3D_WORLD_ERROR_H

# include <cub3d_error.h>

# include "../cub3d_world.h"

# define INNER "02NSWE"

bool	validate_res(char **values);
bool	validate_texture(char *path, char *where);
bool	validate_color(char **rgb, char *area);
bool	validate_layout(t_world *world);
bool	is_first_definition(void *data, char *p_name);
bool	is_layout_pattern(char *line);

#endif
