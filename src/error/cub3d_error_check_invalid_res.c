/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error_check_invalid_resolution.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:48:45 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/17 17:53:09 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Check for a invalid resolution.
** Invalid resolution can be:
**  - Negative values;
**  - One or more than two values;
**  - Alphabetic chars;
** Case one of the above situations are verified, the function print the error -
** message on the screen and return true to sinalize the program to stop.
*/

#include "cub3d_error.h"

bool	check_invalid_res(char **values)
{
	size_t	vi;
	size_t	i;

	vi = 0;
	while (values[vi] != NULL)
	{
		i = 0;
		while (values[vi][i] != '\0')
		{
			if (ft_isalpha(values[vi][i]) || values[vi][i] == '-')
			{
				error_msg("Invalid value for resolution", "cub file");
				return (true);
			}
			++i
		}
		++vi;
	}
	if (vi < 2 || vi > 2)
	{
		error_msg("Resolution must have width and height", "cub file");
		return (true);
	}
}
