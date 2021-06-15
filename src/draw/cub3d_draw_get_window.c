/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_get_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:10:52 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/15 15:17:40 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Initialize a connection with a X-server and create a new window.
** Needs an pointer to pointer to char "res" and pointer to const char title.
** Firstly it will verify if the res values are valid, it means, they are both -
** positive numbers and are up to 2 different values.
*/

static t_window	*create_window(char **res, char *title)
{
	t_window	*ret;

	ret = NULL;
	if (!validate_res(res))
		return (NULL);
	ret = new_window(ft_atoi(res[0]), ft_atoi(res[1]), title);
	if (!ret)
		return (NULL);
	return (ret);
}

/*
** Contains a static t_window that case don't have any value in it, meaning no -
** window were created, will create a new one.
** In all the cases (a window exists or not) it will return the static t_window-
**  address.
** Can receive a line or NULL.
*/

t_window	*get_window(char *line)
{
	static t_window	*window;
	char			**res;

	res = NULL;
	if (line && !is_first_def(window, "Window"))
		return (NULL);
	if (!window)
	{
		window = NULL;
		res = ft_split(line + 1, ' ');
		window = create_window(res, "Cub3D");
		ft_destroyer((void **)res);
		if (!window)
			return (NULL);
	}
	return (window);
}
