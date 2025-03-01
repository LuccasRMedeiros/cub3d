/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error_validate_texture.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:48:48 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/26 22:00:12 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define _GNU_SOURCE

#include "cub3d_error.h"

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * Check for a invalid texture.
 * Receives a file path and will try to open it, then will verify its extension.
 * Invalid texture can be:
 *  - Non existent file;
 *  - File in any format that isn't .bmp;
 * Case one of the above situations been verified, the function prints an error-
 *  message and then returns true to sinalize the program to stop.
 */
int validate_texture(char *path, char *where)
{
    int fd;
    char *error;
    size_t ext_pos;

    fd = open(path, O_RDONLY);
    error = NULL;

    if (fd == -1)
    {
        asprintf(&error, "file: %s was not found", path);
        error_msg(error, where);
        free(error);
        error = NULL;

        return 0;
    }

    close(fd);
    ext_pos = strlen(path) - 4;

    if (strncmp(path + ext_pos, ".xpm", 4) != 0)
    {
        asprintf(&error, "file: %s have invalid format.", path);
        error_msg(error, where);
        free(error);
        error = NULL;

        return 0;
    }

    return 1;
}
