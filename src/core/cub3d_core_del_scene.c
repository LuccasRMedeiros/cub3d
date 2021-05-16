/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_del_scene.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:43:55 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/16 16:09:53 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Destroy a scene.
*/

void	del_scene(t_scene *del)
{
	t_map	*map;

	map = del->map;
	del_map(map);
	del->r_width = 0;
	del->r_height = 0;
	del->floor_color[] = {0, 0, 0};
	del->ceilling_color[] = {0, 0, 0};
	free(del);
}
