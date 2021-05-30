/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_structs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:51:12 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/29 20:18:20 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Header groups the structs and its initalization and destruction functions.
*/

#ifndef CUB3D_DRAW_STRUCTS_H
# define CUB3D_DRAW_STRUCTS_H

# include <stdlib.h>

typedef struct	s_window
{
	void	*con_ptr;
	void	*wndw_ptr;
}	t_window;

t_window	*new_window(void);
void		del_window(t_window *del);

#endif
