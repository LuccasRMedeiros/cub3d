/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_structs_new_window.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:41:43 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/15 15:31:16 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Create a new t_window instance.
*/

#include "cub3d_draw_structs.h"

t_window	*new_window(size_t wdt, size_t hgt, char *title)
{
	t_window	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->res_wdt = wdt;
	new->res_hgt = hgt;
	new->conn = mlx_init();
	if (!new->conn)
	{
		free(new);
		return (NULL);
	}
	new->wndw_ptr = mlx_new_window(new->conn, new->res_wdt,
		new->res_hgt, title);
	return (new);
}
