/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_error.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:27:04 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/25 15:33:24 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Header groups error treatment that may happens on core functions.
*/

#ifndef CUB3D_CORE_ERROR_H
# define CUB3D_CORE_ERROR_H

# include <libft.h>
# include <cub3d_error.h>

# include "../cub3d_core.h"

void	wrong_order(t_world *world);
int		validate_cubfile(char *path);

#endif
