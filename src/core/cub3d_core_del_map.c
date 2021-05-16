/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_del_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 12:14:25 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/16 16:09:55 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Destroy a map.
*/

void	destroy_layout(char **layout)
{
	size_t	lay_i;

	while (layout[lay_i] != NULL)
	{
		layout[lay_i] = NULL;
		free(layout[lay_i]);
		++lay_i;
	}
	free(layout);
}

void	del_map(t_map *del)
{
	char		*name;
	char		**layout;
	t_tile		*tileset;
	t_sprite	*spriteset;

	name = del->name;
	layout = del->layout;
	tileset = del->tileset;
	spriteset = del->spriteset;
	free(name);
	destroy_layout(layout);
	del_tileset(tileset);
	del_spriteset(spriteset);
	del->name = NULL;
	del->tileset = NULL;
	del->spriteset = NULL;
	del->layout = NULL;
	del->map_x = 0;
	del->map_y = 0;
	free(del);
}
