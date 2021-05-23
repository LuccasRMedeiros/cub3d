/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_error.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 15:06:13 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/22 15:13:28 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Header for validation on world creation.
*/

#ifndef CUB3D_WORLD_ERROR_H
# define CUB3D_WORLD_ERROR_H

# include <libft.h>
# include <cubed_world.h>
# include <cub3d_error.h>

# define INNER "02NSWE"

bool	check_invalid_res(char **values);
bool	check_invalid_texture(char *path, char *where);
bool	check_invalid_color(char **rgb, char *area);
bool	check_invalid_layout(const char *layout);

#endif
