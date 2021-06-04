/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_structs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:08:29 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/01 17:19:45 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Header containing structs of Cub3D Core module.
*/

#ifndef CUB3D_CORE_STRUCTS_H
# define CUB3D_CORE_STRUCTS_H

# include <unistd.h>

typedef struct	s_actor
{
	char	id;
	size_t	pos_x;
	size_t	pos_y;
	float	speed;
}	t_actor;
