/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_structs_new_img.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:44:46 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/04 16:51:27 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Creates a t_img instance.
*/

#include "cub3d_draw_structs.h"

t_img	*new_img(void)
{
	t_img	*new;

	new = malloc(sizeof *new);
	new->img = NULL;
	new->addr = NULL;
	new->bpp = 0;
	new->l_len = 0;
	new->endian = 0;
	return (new);
}
