/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_del_sprite.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:04:02 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/24 13:14:42 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Destroy a t_sprite.
*/

#include "cub3d_structs.h"

void	del_sprite(t_sprite *del)
{
	del->id = 0;
	del_img(del->sprite);
	free(del);
}
