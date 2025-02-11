/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error_validate_args.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:23:25 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/31 17:56:10 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_error.h"

/**
 * Check if the user want to take a screen shoot (and called --save correctly).
 */
static int check_save(char *arg)
{
    char error[2048] = { '\0' };

    if (!strncmp(arg, "--save", 7) || !strncmp(arg, "-s", 3))
    {
        return 1;
    }

    snprintf(error, sizeof (error), "%s is not a valid argument, use --save or -s", arg);
    error_msg(error, "Invalid argument at cub3D call");

    return 0;
}

/**
 * Check the file extension, then attempt to open it, case it succed return the-
 *  received fileescriptor.
 */
static int validate_cubfile(char *path)
{
    int fd;

    if (strncmp(strrchr(path, '.'), ".cub", 4))
    {
        error_msg("Please inform a valid cub file", path);

        return -1;
    }

    fd = open(path, O_RDONLY);

    if (fd == -1)
        error_msg("File not found", path);

    return fd;
}

/**
 * Check the number of arguments, and the arguments.
 * If something isn't expected (more than three arguments, invalid entries or  -
 * inversed arguments), output a error message.
 * When the arguments are okay, it return an file descriptor where the "open"  -
 * function placed the cub file.
 */
int validate_args(int argc, char **argv)
{
    if (argc < 2)
    {
        error_msg("Please inform a cub file", "Cub3D call");
        return -1;
    }
    else if (argc > 3)
    {
        error_msg("Too many arguments, inform one cub file and --save or -s",
            "Cub3D call");
        return -1;
    }
    if (argc == 3)
        if (!check_save(argv[2]))
            return -1;
    return validate_cubfile(argv[1]);
}
