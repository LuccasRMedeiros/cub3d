/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:41:45 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/02 18:25:55 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Header for all the structs used in the program.
*/

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

# include <libft.h>
# include <math.h>
# include <mlx.h>

typedef struct	s_sheet
{
	char	id;
	bool	is_wall;
	char	*no_face;
	char	*so_face;
	char	*we_face;
	char	*ea_face;
}	t_sheet;

typedef	struct	s_cub
{
	int		status;
	int		res[2];
	t_sheet	*tilesheet;
	t_sheet	*spritesheet;
	int		f_color[3];
	int		c_color[3];
	char	*pre_lyt;
	char	**layout;
	int		map_axis[2];
	int		player_pos[2];
}	t_cub;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		wdt;
	int		hgt;
	int		bpp;
	int		l_len;
	int		end;
}	t_img;

typedef struct	s_wndw
{
	void	*conn;
	void	*wndw;
	t_img	*screen;
}	t_wndw;

typedef struct s_tile
{
	char	id;
	char	*wall_no;
	char	*wall_so;
	char	*wall_we;
	char	*wall_ea;
}	t_tile;

typedef struct s_sprite
{
	char	id;
	char	*sprite;
}	t_sprite;

typedef struct s_world
{
	t_tile		*tileset;
	t_sprite	*spriteset;
	int			floor;
	int			ceilling;
	char		**map;
	int			map_x;
	int			map_y;
	int			player_x;
	int			player_y;
}	t_world;

t_sheet		*new_sheet(char id, bool is_wall);
void		del_sheet(t_sheet *del);
t_cub		*new_cub(void);
void		del_cub(t_cub *del);
t_img		*new_img(void *conn, size_t wdt, size_t hgt);
void		del_img(void *conn, t_img *del);
t_wndw		*new_window(int wdt, int hgt, char *title);
void		del_window(t_wndw *del);
t_tile		*new_tile(t_sheet *tilesheet);
void		del_tile(t_tile *del);
t_sprite	*new_sprite(t_sheet *spritesheet);
void		del_sprite(t_sprite *del);
t_world		*new_world(t_cub *cub);
void		del_world(t_world *del);

#endif
