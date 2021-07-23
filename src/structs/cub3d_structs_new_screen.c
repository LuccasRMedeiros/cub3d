/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_screen.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:44:46 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/23 20:08:03 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Creates a t_screen instance.
*/

#include "cub3d_structs.h"

t_screen	*new_screen(t_wndw *wndw)
{
	t_screen	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->conn = wndw->conn;
	new->img = mlx_new_image(wndw->conn, wndw->wdt, wndw->hgt);
	new->addr = mlx_get_data_addr(new->img, &new->bpp, &new->l_len, &new->end);
	return (new);
}
