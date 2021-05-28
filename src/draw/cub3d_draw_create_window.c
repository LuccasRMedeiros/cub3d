/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_create_window.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:22:32 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/28 18:46:49 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Initialize a connection with a X-server and create a new window.
*/

#include "cub3d_draw.h"

t_window	*create_window(char **res, const char *title)
{
	t_window	*ret;
	size_t		ww;
	size_t		wh;

	if (!validate_res(res))
		return (NULL);
	ret = new_window();
	ww = ft_atoi(res[0]);
	wh = ft_atoi(res[1]);
	ret->con_ptr = mlx_init();
	if (!ret->con_ptr)
		return (NULL);
	ret->wndw_ptr = mlx_new_window(ret->con_ptr, ww, wh, (char *)title);
	return (ret);
}
