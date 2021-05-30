/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_read_cub.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:10:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/29 22:10:13 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Reads a informed .cub file, so it starts to set correct values for world    -
** members.
*/

#include "cub3d_core.h"

static void	select_case_line(char *line, t_world *world, int gnl_stts)
{
	if (world->status == -1)
		return ;
	if (!ft_strncmp(line, "R", 1))
	{
		if (!ret_window(line))
			world->status = -1;
	}
	else if(!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
		|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
		set_tileset(line, world);
	else if (!ft_strncmp(line, "S", 1))
		set_spriteset(line, world);
	else if (!ft_strncmp(line, "F", 1))
		set_floor_color(line, world);
	else if (!ft_strncmp(line, "C", 1))
		set_ceilling_color(line, world);
	else if (world->status == 8)
		set_map(line, world, gnl_stts);
	else if (is_map_pattern(line))
		wrong_order(world);
}

t_world	*read_cub(char *cub_path)
{
	t_world	*world;
	int		fd;
	int		gnl_stts;
	char	*line;

	world = new_world();
	fd = validate_cubfile(cub_path);
	if (fd == -1)
	{
		world->status = -1;
		return (world);
	}
	gnl_stts = 1;
	world->name = ft_strdup(cub_path + 7);
	while (gnl_stts)
	{
		gnl_stts = ft_gnl(fd, &line);
		select_case_line(line, world, gnl_stts);
		free(line);
	}
	close(fd);
	return (world);
}
