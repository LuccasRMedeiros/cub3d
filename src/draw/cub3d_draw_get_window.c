/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_get_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:10:52 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/01 14:21:34 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Contains a static t_window that case don't have any value in it, meaning no -
** window were created, will create a new one.
** In all the cases (a window exists or not) it will return the static t_window-
**  address.
** Can receive a line or NULL.
*/

#include "cub3d_draw.h"

t_window	*get_window(char *line)
{
	static t_window	*window;
	char			**res;

	res = NULL;
	if (line)
	{
		res = ft_split(line + 1, ' ');
		window = create_window(res, "Cub3D");
		ft_destroyer((void **)res);
		if (!window)
			return (NULL);
	}
	return (window);
}
