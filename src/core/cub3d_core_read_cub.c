/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_read_cub.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:10:34 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/24 11:02:26 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_core.h"

/*
** Call the function that deals with certain type of information.
** The first verification it does is if the cub status is -1 which means an    -
** error was found on the given cub file. If it happens, the select case return-
**  to continue the read of the cub file. It is done to prevent to grant the   -
** program will read a fil till the end, avoiding a memory leak.
*/

static void	select_case_line(char *line, t_cub *cub, int gnl_stts)
{
	if (cub->status == -1)
		return ;
	if (!ft_strncmp(line, "R", 1))
		set_res(line, cub);
	else if(!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
		|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
		set_tilesheet(line, cub);
	else if (!ft_strncmp(line, "S", 1))
		set_spritesheet(line, cub);
	else if (!ft_strncmp(line, "F", 1))
		set_floor_color(line, cub);
	else if (!ft_strncmp(line, "C", 1))
		set_ceilling_color(line, cub);
	else if (cub->status == 8)
		set_map(line, cub, gnl_stts);
	else if (is_map_pattern(line))
		wrong_order(cub);
}

/*
** Reads a informed .cub file, so it starts to set correct values for world    -
** members.
*/

t_cub	*read_cub(char *cub_path)
{
	t_cub	*cub;
	int		fd;
	int		gnl_stts;
	char	*line;

	cub = new_cub();
	fd = validate_cubfile(cub_path);
	if (fd == -1)
	{
		cub->status = -1;
		return (cub);
	}
	gnl_stts = 1;
	while (gnl_stts)
	{
		gnl_stts = ft_gnl(fd, &line);
		select_case_line(line, cub, gnl_stts);
		free(line);
	}
	close(fd);
	return (cub);
}
