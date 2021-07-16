/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_actor.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:32:21 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/15 19:14:11 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Will return a double value according to what char represent the player.
** This char can be 'N', 'S', 'W' or 'E', they reffer to what direction the    -
** player start looking to.
** The function must be unreacheble if a invald direction be informed. It means-
**  the return 0 is symbolic (also it turn possible the program to be compiled,-
** another solution would be to return any of the values below out of the "if  -
** else if" branch, but this way make things humanly readable).
*/

static double	select_dir(char dir)
{
	if (dir == 'W')
		return (PI);
	else if (dir == 'N')
		return (PI / 2);
	else if (dir == 'E')
		return (PI * 2);
	else if (dir == 'S')
		return ((PI * 3) / 2);
	return (0);
}

/*
** Create a new t_actor instance.
*/

t_actor	*new_actor(char dir, int pos_x, int pos_y)
{
	t_actor	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->id = 'P';
	new->map_x = pos_x;
	new->map_y = pos_y;
	new->abs_x = pos_x;
	new->abs_y = pos_y;
	new->dir = select_dir(dir);
	new->delta_x = cos(dir) * 5;
	new->delta_y = sin(dir) * 5;
	return (new);
}
