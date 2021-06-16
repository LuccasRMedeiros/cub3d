/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_structs_del_actor.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:41:20 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/16 13:53:57 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Destroy a t_actor instance.
*/

#include "cub3d_core_structs.h"

void	del_actor(t_actor *del)
{
	del->id = 0;
	del->pos_x = 0;
	del->pos_y = 0;
	del_img(del->sprite);
	free(del);
}
