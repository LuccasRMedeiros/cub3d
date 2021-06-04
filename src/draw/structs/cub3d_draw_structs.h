/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_structs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:51:12 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/04 16:51:27 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Header groups the structs and its initalization and destruction functions.
*/

#ifndef CUB3D_DRAW_STRUCTS_H
# define CUB3D_DRAW_STRUCTS_H

# include <stdlib.h>
# include <mlx.h>

typedef struct	s_window
{
	size_t	res_wdt;
	size_t	res_hgt;
	void	*con_ptr;
	void	*wndw_ptr;
}	t_window;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
}	t_img;

t_window	*new_window(void);
void		del_window(t_window *del);

#endif
