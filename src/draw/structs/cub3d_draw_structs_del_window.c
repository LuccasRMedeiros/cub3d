/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_structs_del_window.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:55:51 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/15 15:30:06 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Destroy a t_window instance.
** Requires the address to the t_window instance to be destroyed.
*/

#include "cub3d_draw_structs.h"

void	del_window(t_window *del)
{
	mlx_destroy_window(del->conn, del->wndw_ptr);
	del->res_wdt = 0;
	del->res_hgt = 0;
	del->conn = NULL;
	del->wndw_ptr = NULL;
	free(del);
}
