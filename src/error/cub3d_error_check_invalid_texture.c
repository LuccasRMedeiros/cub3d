/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error_check_invalid_texture.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:48:48 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/17 18:03:19 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Check for a invalid texture.
** Receives a file path and will try to open it, then will verify its extension.
** Invalid texture can be:
**  - Non existent file;
**  - File in any format that isn't .bmp;
** Case one of the above situations been verified, the function prints an error -
** message and then returns true to sinalize the program to stop.
*/

#include "cub3d_error.h"

bool	check_invalid_texture(char *path)
{
	int		fd;
	char	error;
	size_t	ext_pos;

	fd = open(path, O_RDONLY);
	error = NULL;
	if (fd == -1)
	{
		error = ft_strcomb(3, "file: ", path, " was not found.");
		error_msg(error, "cub file");
		error = NULL;
		free(error);
		return (true);
	}
	close(fd);
	ext_pos = ft_strlen(path) - 4;
	if (ft_strncmp(line + ext_pos, ".bmp", 4) != 0)
	{
		error = ft_strcomb(3, "file: ", path, " have invalid format.");
		error_msg(error, "texture file");
		error = NULL;
		free(error);
		return (true);
	}
	return (false);
}

