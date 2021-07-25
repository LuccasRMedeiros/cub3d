/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_del_column.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 00:12:17 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/25 01:15:17 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Delete a t_column instance.
*/

void    del_column(t_column *del)
{
    del->d_proj = 0;
    del->perp_d = 0;
    del->hgt = 0;
	del->org_sy = 0;
	del->end_sy = 0;
	del->ox = 0;
	free(del);
}