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

/**
 * Check for a invalid resolution.
 * Invalid resolution can be:
 *  - Negative values;
 *  - One or more than two values;
 *  - Alphabetic chars;
 * Case one of the above situations are verified, the function print the error 
 * message on the screen and return true to sinalize the program to stop.
 */
int validate_res(char **values)
{
    for (size_t sa = 0; values[sa] != NULL; ++sa)
    {
        for (size_t i = 0; values[sa][i] != '\0'; ++i)
        {
            if (isalpha(values[sa][i]) || values[sa][i] == '-')
            {
                error_msg("Invalid value for resolution", "Resolution");

                return 0;
            }
        }
    }

    if (sa < 2 || sa > 2)
    {
        error_msg("Resolution must have width and height", "Resolution");

        return 0;
    }

    return 1;
}
