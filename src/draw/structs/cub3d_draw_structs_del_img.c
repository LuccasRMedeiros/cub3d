/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_structs_del_img.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:49:24 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/04 16:51:27 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Delete the informed t_img instance.
*/

#include "cub3d_draw_structs.h"

void	del_img(t_img *del)
{
	del->img = NULL;
	del->addr  = NULL;
	del->bpp = 0;
	del->l_len = 0;
	del->endian = 0;
	free(del);
}
