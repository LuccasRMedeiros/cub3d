/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_del_img.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:49:24 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/01 18:54:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Delete the informed t_img instance.
*/

#include "cub3d_structs.h"

void	del_img(void *conn, t_img *del)
{
	mlx_destroy_image(conn, del->img);
	free(del);
	del->img = NULL;
	del->addr  = NULL;
	del->bpp = 0;
	del->l_len = 0;
	del->end = 0;
}