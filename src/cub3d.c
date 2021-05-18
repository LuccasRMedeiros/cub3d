/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:19:26 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/18 17:09:47 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Main function.
** Will create a new window and will start the game, if a error where found the-
**  program closes.
*/

#include <cub3d_core.h>
#include <cub3d_draw.h>
#include <cub3d_error.h>

int	main(int argc, char **argv)
{
	if (read_cub(*argv[0]) == -1)
		exit(-1);
	do_nothing();
	return (0);
}
