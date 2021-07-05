/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_img.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:44:46 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/04 13:47:32 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Creates a t_img instance.
*/

#include "cub3d_structs.h"

t_img	*new_img(t_wndw *wndw)
{
	t_img	*new;

	new = malloc(sizeof *new);
	new->conn = wndw->conn;
	new->img = mlx_new_image(wndw->conn, wndw->wdt, wndw->hgt);
	new->addr = mlx_get_data_addr(new->img, &new->bpp, &new->l_len, &new->end);
	return (new);
}
