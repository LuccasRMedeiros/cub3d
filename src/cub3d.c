/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:19:26 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/19 15:17:19 by lrocigno         ###   ########.fr       */
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
	t_scene	*scene;

	scene = read_cub(argv[1]);
	if (scene->status == -1)
	{
		del_scene(scene);
		exit(-1);
	}
	del_scene(scene);
	return (argc);
}
