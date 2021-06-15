/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_structs_new_img.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:44:46 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/15 15:10:38 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Creates a t_img instance.
*/

#include "cub3d_draw_structs.h"

t_img	*new_img(void *conn, size_t wdt, size_t hgt)
{
	t_img	*new;

	new = malloc(sizeof *new);
	new->img = mlx_new_image(conn, wdt, hgt);
	new->addr = mlx_get_data_addr(new->img, &new->bpp, &new->l_len, &new->end);
	return (new);
}
