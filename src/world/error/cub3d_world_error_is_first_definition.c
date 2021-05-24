/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_world_error_is_first_definition.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:33:36 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/23 19:51:44 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Verifies if the scene member that is about to be filled already have some   -
** data.
** Receives an address to member data and the property name. Case the address  -
** have some value, the function will emit a error message and sinalize the    -
** program to stop.
*/

#include "cub3d_world_error.h"

bool	is_first_definition(char *data, char *p_name)
{
	if (data != NULL)
	{
		error_msg("Double definition for property", p_name);
		return (false);
	}
	return (true);
}
