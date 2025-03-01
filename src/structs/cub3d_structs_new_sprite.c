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

#include "cub3d_structs.h"

/**
 * Initialize a new t_sprite.
 */
st_sprite *new_sprite(st_sheet *spritesheet, st_wndw *wndw)
{
    st_sprite *new;

    new = malloc(sizeof(*new));

    if (!new)
        return NULL;

    new->id = spritesheet->id;
    new->sprite = new_img(wndw, 0, 0, spritesheet->no_face);

    return new;
}
