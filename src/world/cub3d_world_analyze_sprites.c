/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_analyze_sprites.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 14:52:00 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/30 17:20:36 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_world.h"

/*
** Sort the sprites accordingly to their distance from the player.
*/

static void	sort_sprites(t_static_obj *spt_list, int n_spts)
{
	int				el;
	t_static_obj	temp;

	el = 0;
	while (el < n_spts - 1)
	{
		if (spt_list[el].obj.dist < spt_list[el + 1].obj.dist)
		{
			temp = spt_list[el];
			spt_list[el] = spt_list[el + 1];
			spt_list[el + 1] = temp;
		}
		++el;
	}
}

/*
** Use the list of sprites to calculate the distance between the sprite and the-
**  player.
*/

void	analyze_sprites(t_wndw *wndw,
						t_world *wrld,
						t_actor *p,
						t_static_obj *spt_list)
{
	int	el;

	el = 0;
	while (el < wrld->n_sprites)
	{
		spt_list[el].obj = new_obj(wndw, p, spt_list[el]);
		++el;
	}
	sort_sprites(spt_list, wrld->n_sprites);
}
