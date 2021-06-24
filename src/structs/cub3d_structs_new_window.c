/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_window.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:41:43 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/24 11:00:23 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Create a new t_window instance.
*/

#include "cub3d_structs.h"

t_window	*new_window(void *conn, size_t wdt, size_t hgt, char *title)
{
	t_window	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->res_wdt = wdt;
	new->res_hgt = hgt;
	new->conn = conn;
	if (!new->conn)
	{
		free(new);
		return (NULL);
	}
	new->wndw_ptr = mlx_new_window(conn, new->res_wdt, new->res_hgt, title);
	return (new);
}
