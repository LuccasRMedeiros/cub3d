/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:19:26 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/16 01:27:09 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_core.h>

/*
** Create window and world instances using the information obtained from the   -
** cub buffer.
** When it finishes, destroy the cub and return a t_program containing the     -
** window and the world addresses.
*/

static t_program	prog_config(t_cub *cub)
{
	t_program	prog;

	prog.running = true;
	prog.wndw = new_window(cub->res[0], cub->res[1], "Cub3D");
	prog.wrld = new_world(cub);
	prog.player = new_actor('P', cub->player_pos[0], cub->player_pos[1]);
	del_cub(cub);
	return (prog);
}

/*
** Calls for ret_window to receive the main t_window instance (created during  -
** read_cub call), it is assumed that the program will only enter this function-
**  if all the needed information was provided in the cub file, what means that-
**  a window was already created.
*/

static void	cub3d(t_program prog)
{
	update_frame(prog.wndw, prog.wrld);
	mlx_hook(prog.wndw->wndw, 2, 1L<<0, key_pressed, &prog);
	mlx_hook(prog.wndw->wndw, 3, 1L<<0, key_released, &prog);
	mlx_loop(prog.wndw->conn);
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
	cub3d(prog_config(cub));
	return (argc);
}
