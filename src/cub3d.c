/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:19:26 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/28 16:30:06 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Main function.
** Will create a new window and will start the game, if a error where found the-
**  program closes.
*/

#include <cub3d_core.h>

int	main(int argc, char **argv)
{
	t_world	*world;

	world = read_cub(argv[1]);
	if (world->status == -1)
	{
		del_world(world);
		exit(-1);
	}
	print_map(world);
	del_world(world);
	return (argc);
}
