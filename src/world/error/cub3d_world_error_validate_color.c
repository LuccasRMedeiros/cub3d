/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_error_validate_color.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:20:06 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/23 12:30:11 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Check if the informed color is invalid.
** A invalid color can be:
**  - A group of less than three values or more than three values;
**  - One or more values are negative;
**  - One or more values are greater than 255.
** Case one of the above conditions be verified, the function emits a error    -
** message and returns true to sinalize the program to stop.
*/

#include "cub3d_error.h"

bool	validate_color(char **rgb, char *area)
{
	int		value;
	size_t	rgb_i;

	rgb_i = 0;
	while (rgb[rgb_i] != NULL)
	{
		value = ft_atoi(rgb[rgb_i]);
		if (value > 255 || value < 0)
		{
			error_msg("Invalid color", area);
			ft_destroyer((void **)rgb);
			return (false);
		}
		++rgb_i;
	}
	if (rgb_i < 3 || rgb_i > 3)
	{
		error_msg("The color must be composed by RGB", area);
		ft_destroyer((void **)rgb);
		return (false);
	}
	return (true);
}
