/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_structs_del_window.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:55:51 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/25 15:10:33 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Destroy a t_window instance.
** Requires the address to the t_window instance to be destroyed.
*/

#include "cub3d_draw_structs.h"

void	del_window(t_window *del)
{
	char	*title;

	name = del->title;
	free(name);
	name = NULL;
	del->status = 0;
	del->res[0] = 0;
	del->res[1] = 0;
	del->wndw_ptr = NULL;
	free(del);
}
