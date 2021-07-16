/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 11:44:11 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/16 01:17:39 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Header with the difinitions and prototypes for world pre-building functions.
*/

#ifndef CUB3D_WORLD_H
# define CUB3D_WORLD_H

# include <cub3d_structs.h>

#define	EXIT 0xff1b
#define	FWRD 0x77
#define	REAR 0x73
#define	RGHT 0x64
#define	LEFT 0x61
#define	TRGT 0xff53
#define	TLFT 0xff51

void    navigate(t_world *wrld, t_actor *player, int key);

#endif
