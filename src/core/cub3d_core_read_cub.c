/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_read_cub.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:10:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/25 15:54:58 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Reads a informed .cub file, so it starts to set correct values for world    -
** members.
** Even if the world is created here, later it will be reposability of draw    -
** functions to properly renderize it.
*/

#include "cub3d_core.h"

static void	select_case_line(char *line, t_world *world, int gnl_stts)
{
	if (!ft_strncmp(line, "R", 1))
		do_nothing();
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
		set_layout(line, world, gnl_stts);
	else if (is_layout_pattern(line))
		wrong_order(world);
	if (world->status == -1)
	{
		exit(-1);
		del_world(world);
	}
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
		exit(-1);
	}
	gnl_stts = 1;
	world->map->name = ft_strdup(cub_path);
	while (gnl_stts)
	{
		gnl_stts = ft_gnl(fd, &line);
		select_case_line(line, world, gnl_stts);
		free(line);
	}
	close(fd);
	return (world);
}
