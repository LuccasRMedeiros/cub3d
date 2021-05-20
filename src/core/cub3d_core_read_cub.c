/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_read_cub.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:10:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/20 17:54:41 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Reads a informed .cub file, so it starts to set correct values for scene    -
** members.
** Even if the scene is created here, later it will be reposability of draw    -
** functions to properly renderize it.
*/

#include "cub3d_core.h"

void	select_case_line(char *line, t_scene *scene, int gnl_stts)
{
	if (line[0] == '\n')
		return ;
	else if (!ft_strncmp(line, "R", 1))
		set_scene_resolution(line, scene);
	else if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
		|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
		set_tileset(line, scene);
	else if (!ft_strncmp(line, "S", 1))
		set_spriteset(line, scene);
	else if (!ft_strncmp(line, "F", 1))
		set_floor_color(line, scene);
	else if (!ft_strncmp(line, "C", 1))
		set_ceilling_color(line, scene);
	else if (scene->status == 12)
		set_layout(line, scene, gnl_stts);
	else if (scene->status == -1)
		exit(-1);
}

t_scene	*read_cub(char *cub_path)
{
	t_scene	*scene;
	int		fd;
	int		gnl_stts;
	char	*line;

	scene = new_scene();
	fd = open(cub_path, O_RDONLY);
	gnl_stts = 1;
	if (fd == -1)
	{
		error_msg("File not found", "informed cub file");
		scene->status = -1;
		exit(-1);
	}
	while (gnl_stts)
	{
		gnl_stts = ft_gnl(fd, &line);
		select_case_line(line, scene, gnl_stts);
	}
	close(fd);
	return (scene);
}
