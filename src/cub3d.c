/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:19:26 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/15 17:03:39 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_core.h>

/*
** Will draw a character on the screen. Just a placeholder.
*/

static void	player(void)
{
	t_window	*wndw;
	t_img		*player;
	int			hgt;
	int			wdt;

	wndw = get_window(NULL);
	player = new_img(wndw->conn, 32, 32);
	hgt = 0;
	wdt = 0;
	while (hgt < 32)
	{
		while (wdt < 32)
		{
			pixel_put(player, hgt, wdt, 0xFFFFFF);
			++wdt;
		}
		wdt = 0;
		pixel_put(player, hgt, wdt, 0xFFFFFF);
		++hgt;
	}
	mlx_put_image_to_window(wndw->conn, wndw->wndw_ptr, player->img, 0, 0);
}

/*
** Calls for ret_window to receive the main t_window instance (created during  -
** read_cub call), it is assumed that the program will only enter this function-
**  if all the needed information was provided in the cub file, what means that-
**  a window was already created.
*/

static void	window(t_world *world)
{
	t_window *wndw;

	wndw = get_window(NULL);
	mlx_hook(wndw->wndw_ptr, 2, 1L<<0, key_pressed, world);
	mlx_hook(wndw->wndw_ptr, 3, 1L<<0, key_released, wndw);
	player();
	mlx_loop(wndw->conn);
}

/*
** Main function.
** Call for read_cub to parse the information into a t_world instance. If the  -
** informed cub file be all right the main function will continue the program  -
** execution going to "window", but case the world returns with a -1 status it -
** will delete that t_world instance and then will close the program.
*/

int	main(int argc, char **argv)
{
	t_world	*world;

	world = read_cub(argv[1]);
	if (world->status == -1)
	{
		del_world(world);
		exit(-1);
	}
	window(world);
	return (argc);
}
