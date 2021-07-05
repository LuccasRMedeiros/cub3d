/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_del_window.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:07:16 by user42            #+#    #+#             */
/*   Updated: 2021/07/04 19:55:30 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Delete a window.
*/

void	del_window(t_wndw *del)
{
	mlx_destroy_window(del->conn, del->wndw);
	ft_lstclear(&del->frame, &del_img);
	mlx_destroy_display(del->conn);
	free(del);
	del->conn = NULL;
	del->wndw = NULL;
}
