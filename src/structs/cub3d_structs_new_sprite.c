/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_sprite.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:56:31 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/31 18:17:25 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Initialize a new t_sprite.
*/

#include "cub3d_structs.h"

t_sprite	*new_sprite(t_sheet *spritesheet, t_wndw *wndw)
{
	t_sprite	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->id = spritesheet->id;
	new->sprite = new_img(wndw, 0, 0, spritesheet->no_face);
	return (new);
}
