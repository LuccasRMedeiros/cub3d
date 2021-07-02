/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error_validate_cubfile.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:13:22 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/23 19:22:57 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Verify if the informed cub file is valid.
** Requires the path for such file.
** First check if the file is a cub file, if so hen it tries to open, receiving-
**  a valid file descriptor it returns this value. Case the file isn't valid or-
**  doesn't exists, emit an error message and return -1.
*/

#include "cub3d_error.h"

int	validate_cubfile(char *path)
{
	int	fd;
	
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_msg("File not found", path);
	if (ft_strncmp(ft_strrchr(path, '.'), ".cub", 4))
	{
		error_msg("Please inform a valid cub file", path);
		return (-1);
	}
	return (fd);
}