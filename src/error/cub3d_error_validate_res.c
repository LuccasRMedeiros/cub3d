/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error_validate_res.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:48:45 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/23 19:13:50 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_error.h"

/*
** Check for a invalid resolution.
** Invalid resolution can be:
**  - Negative values;
**  - One or more than two values;
**  - Alphabetic chars;
** Case one of the above situations are verified, the function print the error -
** message on the screen and return true to sinalize the program to stop.
*/

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
				error_msg("Invalid value for resolution", "Resolution");
				return (false);
			}
			++i;
		}
		++sa;
	}
	if (sa < 2 || sa > 2)
	{
		error_msg("Resolution must have width and height", "Resolution");
		return (false);
	}
	return (true);
}
