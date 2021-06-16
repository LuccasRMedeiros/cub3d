/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:19:26 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/16 17:53:46 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_core.h>

/*
** Will draw a character on the screen. Just a placeholder.
*/

static void	player(void)
{
	t_window	*wndw;
	t_actor		*player;
	int			hgt;
	int			wdt;

	wndw = get_window(NULL);
	player = new_actor('N', 0, 0);
	player->sprite = new_image(wndw->conn, 32, 32);
	t_img		*sprite;
	hgt = 0;
	wdt = 0;
	while (hgt < 32)
	{
		while (wdt < 32)
		{
			pixel_put(sprite, hgt, wdt, 0xFFFFFF);
			++wdt;
		}
		wdt = 0;
		pixel_put(sprite, hgt, wdt, 0xFFFFFF);
		++hgt;
	}
	player->sprite = sprite;
	mlx_put_image_to_window(wndw->conn, wndw->wndw_ptr, player->sprite->img, player->pos_x, player->pos_y);
}

/*
** Calls for ret_window to receive the main t_window instance (created during  -
** read_cub call), it is assumed that the program will only enter this function-
**  if all the needed information was provided in the cub file, what means that-
**  a window was already created.
*/

static void	cub3d(t_world *world)
{
	t_window *wndw;

	wndw = get_window(NULL);
	mlx_hook(wndw->wndw_ptr, 2, 1L<<0, key_pressed, world);
	mlx_hook(wndw->wndw_ptr, 3, 1L<<0, key_released, wndw);
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
	player();
	cub3d(world);
	return (argc);
}
