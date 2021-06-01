/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_create_window.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:22:32 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/30 12:02:03 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Initialize a connection with a X-server and create a new window.
** Needs an pointer to pointer to char "res" and pointer to const char title.
** Firstly it will verify if the res values are valid, it means, they are both -
** positive numbers and are up to 2 different values.
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