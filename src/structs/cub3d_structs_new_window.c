/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_window.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:05:08 by user42            #+#    #+#             */
/*   Updated: 2021/07/23 22:28:29 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Create a window using the provided informations.
** The mlx connection must be initialized before 
** It finishes creating a image that covers all the window. This image called  -
** screen is where the pixels are drawed.
*/

t_wndw	*new_window(int wdt, int hgt, char *title)
{
	t_wndw	*new;
	int		max_wdt;
	int		max_hgt;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->conn = mlx_init();
	mlx_get_screen_size(new->conn, &max_wdt, &max_hgt);
	if (wdt > max_wdt)
		wdt = max_wdt;
	if (hgt > max_hgt)
		hgt = max_hgt;
	new->wdt = wdt;
	new->hgt = hgt;
	new->wndw = mlx_new_window(new->conn, wdt, hgt, title);
	return (new);
}
