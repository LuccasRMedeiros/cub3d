/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_read_cub.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:10:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/18 22:29:33 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Reads a informed .cub file, so it starts to set correct values for scene    -
** members.
** Even if the scene is created here, later it will be reposability of draw    -
** functions to properly renderize it.
*/

#include "cub3d_core.h"

void	select_case_line(char *line, t_scene *scene)
{
	if (!ft_strncmp(line, "R", 1))
		set_scene_resolution(line, scene);
	else if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2) 
			|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
		set_tileset(line, scene);
	else if (!ft_strncmp(line, "S", 1))
		set_spriteset(line, scene);
	else if (!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
		do_nothing();
	else
		read_cub_error();
	if (scene->status == 10)
		do_nothing();
	else if (scene->status == -1)
		exit(-1);
}

t_scene	*read_cub(char *cub_path)
{
	t_scene	*scene;
	int		fd;
	char	*line;
	int		gnl_finish;

	scene = new_scene();
	fd = open(cub_path, O_RDONLY);
	while (ft_gnl(fd, &line))
		select_case_line(line);
	if (scene->status == -1)
		while(gnl_finish)
			gnl_finish = ft_gnl(fd, &line);
	close(fd);
	return (scene);
}
