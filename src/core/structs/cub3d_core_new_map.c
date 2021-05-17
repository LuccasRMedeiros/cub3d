/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_new_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:17:28 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/16 16:09:56 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Create a new t_map.
*/

t_map	*new_map(void)
{
	t_map	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->name = NULL;
	new->tileset = new_tile();
	new->spriteset = new_sprite();
	new->layout = NULL;
	new->map_x = 0;
	new->map_y = 0;
}
