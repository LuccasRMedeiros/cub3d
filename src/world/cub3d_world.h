/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 11:44:11 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/16 13:28:49 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Header with the difinitions and prototypes for world pre-building functions.
*/

#ifndef CUB3D_WORLD_H
# define CUB3D_WORLD_H

# include <cub3d_structs.h>

void    navigate(t_world *wrld, t_actor *player, int key);

#endif
