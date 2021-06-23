/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_del_world.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 12:14:25 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/23 18:35:50 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Destroy a world.
*/

#include "cub3d_structs.h"

void	del_world(t_world *del)
{
	ft_destroyer(del->map);
	del->map_x = 0;
	del->map_y = 0;
	free(del);
}
