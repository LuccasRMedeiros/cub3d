/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_del_img.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:49:24 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/31 18:24:38 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Delete the informed t_img instance.
*/

#include "cub3d_structs.h"

void	del_img(t_img *del)
{
	if (!del)
		return ;
	mlx_destroy_image(del->conn, del->img);
	del->img = NULL;
	del->addr = NULL;
	del->wdt = 0;
	del->hgt = 0;
	del->bpp = 0;
	del->l_len = 0;
	del->end = 0;
	free(del);
}
