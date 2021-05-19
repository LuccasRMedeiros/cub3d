/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_del_sprite.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:04:02 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/19 11:32:58 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Destroy a t_sprite.
*/

#include "cub3d_core_structs.h"

void	del_sprite(t_sprite *del)
{
	del->id = 0;
	del->sprite = NULL;
	free(del);
}
