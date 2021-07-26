/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_img.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:44:46 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/25 12:07:17 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Creates a t_img instance.
*/

#include "cub3d_structs.h"

t_img	*new_img(t_wndw *wndw, int wdt, int hgt, char *file_path)
{
	t_img	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->conn = wndw->conn;
	new->wdt = wdt;
	new->hgt = hgt;
	if (!file_path)
		new->img = mlx_new_image(wndw->conn, wdt, hgt);
	else
	{
		new->img = mlx_xpm_file_to_image(new->conn, file_path,
			&new->wdt, &new->hgt);
	}
	new->addr = (int *)mlx_get_data_addr(new->img, &new->bpp,
		&new->l_len, &new->end);
	return (new);
}
