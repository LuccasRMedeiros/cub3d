/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_del_window.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:07:16 by user42            #+#    #+#             */
/*   Updated: 2021/07/01 21:31:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Delete a window.
*/

void	del_window(t_wndw *del)
{
	del_img(del->conn, del->screen->img);
	mlx_destroy_window(del->conn, del->wndw);
	mlx_destroy_display(del->conn);
	free(del);
	del->conn = NULL;
	del->wndw = NULL;
}
