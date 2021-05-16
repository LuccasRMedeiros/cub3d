/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_scene_parser.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:10:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/16 20:23:32 by lrocigno         ###   ########.fr       */
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
	if (!ft_strncmp(line, "R", 1)
		do_something;
	else if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2) 
			|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
		do_something;
	else if (!ft_strncmp(line, "S", 1))
		do_something;
	else if (!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
		do_something;
	if (scene->res && scene->floor_color && scene->ceilling_color)
		do_something;
}

t_scene	*compose_scene(char *cub_path)
{
	t_scene	*scene;
	int		fd;
	char	*line;

	scene = new_scene();
	fd = open(cub_path, O_RDONLY);
	while (ft_gnl(fd, &line))
		select_case_line(line);
	return (scene);
}
