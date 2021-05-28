/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_error_validate_res.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:48:45 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/28 14:58:01 by lrocigno         ###   ########.fr       */
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

#include "cub3d_draw_error.h"

bool	validate_res(char **values)
{
	size_t	sa;
	size_t	i;

	sa = 0;
	while (values[sa] != NULL)
	{
		i = 0;
		while (values[sa][i] != '\0')
		{
			if (ft_isalpha(values[sa][i]) || values[sa][i] == '-')
			{
				error_msg("Invalid value for resolution", "resolution");
				return (false);
			}
			++i;
		}
		++sa;
	}
	if (sa < 2 || sa > 2)
	{
		error_msg("Resolution must have width and height", "resolution");
		return (false);
	}
	return (true);
}
