/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error_invalid_resolution.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:19:27 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/16 19:08:04 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function verify if the R values are valid as a resolution.
** They can't be:
**  - More than tree;
**  - Negative;
**  - Alphabetic;
** Case one of the conditions be verified as true, the program will emit a     -
** error message and the returns true to indicate that the error was found.    -
** Else, it returns false and the program is allowed to continue.
*/

#include "cub3d_error.h"

bool	invalid_resolution(char *line)
{
	line = ft_strtrim(line + 1, " ");
	while (*line != 0)
	{
		if (!ft_isdigit(*line))
		{
			error_msg("Invalid resolution.", "cub file");
			return (true);
		}
		++line;
	}
	return (false);
}
