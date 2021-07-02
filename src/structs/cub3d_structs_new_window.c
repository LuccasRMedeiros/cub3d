/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_window.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:05:08 by user42            #+#    #+#             */
/*   Updated: 2021/07/01 21:33:19 by user42           ###   ########.fr       */
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

	new = malloc(sizeof new);
	if (!new)
		return (NULL);
	new->conn = mlx_init();
	new->wndw = mlx_new_window(new->conn, wdt, hgt, title);
	new->screen = new_img(new->conn, wdt, hgt);
	return (new);
}
