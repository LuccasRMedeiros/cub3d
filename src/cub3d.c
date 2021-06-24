/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:19:26 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/24 15:24:27 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_core.h>

/*
** Calls for ret_window to receive the main t_window instance (created during  -
** read_cub call), it is assumed that the program will only enter this function-
**  if all the needed information was provided in the cub file, what means that-
**  a window was already created.
*/

static void	cub3d(t_cub *cub)
{
	void		*conn;
	t_window	*wndw;
	t_world		*world;
	t_program	prog;

	conn = mlx_init();
	wndw = new_window(conn, cub->res[0], cub->res[1], "Cub3D");
	world = set_world(cub, conn);
	del_cub(cub);
	prog.wndw = wndw;
	prog.wrld = world;
	mlx_hook(wndw->wndw_ptr, 2, 1L<<0, key_pressed, &prog);
	mlx_hook(wndw->wndw_ptr, 3, 1L<<0, key_released, &prog);
	mlx_loop(conn);
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
	t_cub	*cub;

	cub = read_cub(argv[1]);
	if (cub->status == -1)
	{
		del_cub(cub);
		exit(-1);
	}
	cub3d(cub);
	return (argc);
}
