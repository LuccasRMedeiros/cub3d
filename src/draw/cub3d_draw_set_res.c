/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_set_res.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:21:03 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/25 15:03:23 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Configure properly the resolution for a t_window instance.
** It is assumed that the program enter on this function only when gnl finds a -
** line that begins with "R".
*/

void	set_res(char *line, t_window *window)
{
	char	**values;

	values = ft_split(line + 1, ' ');
	if (!validate_res(values))
	{
		window->status = -1;
		return ;
	}
	window->res[0] = values[0];
	window->res[1] = values[1];
	window->status = 20;
}
