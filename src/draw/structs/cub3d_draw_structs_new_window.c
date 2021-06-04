/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_structs_new_window.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:41:43 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/01 17:25:30 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Create a new t_window instance.
*/

#include "cub3d_draw_structs.h"

t_window	*new_window(void)
{
	t_window	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->res_wdt = 0;
	new->res_hgt = 0;
	new->con_ptr = NULL;
	new->wndw_ptr = NULL;
	return (new);
}
