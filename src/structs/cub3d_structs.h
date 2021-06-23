/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:41:45 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/23 19:34:13 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Header for all the structs used in the program.
*/

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

# include <unistd.h>

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
	int		floor_color[3];
	int		ceilling_color[3];
	char	*pre_layout;
	char	**layout;
	int		map_axis[2];
	int		player_pos[2];
}	t_cub;

typedef struct	s_window
{
	size_t	res_wdt;
	size_t	res_hgt;
	void	*conn;
	void	*wndw_ptr;
}	t_window;

typedef struct	s_img
{
	char	*name;
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		end;
}	t_img;

typedef struct s_tile
{
	char	id;
	t_img	*wall_no;
	t_img	*wall_so;
	t_img	*wall_we;
	t_img	*wall_ea;
}	t_tile;

typedef struct s_sprite
{
	char	id;
	t_img	*sprite;
}	t_sprite;

typedef struct s_world
{
	t_tile		*tileset;
	t_sprite	*spriteset;
	t_img		*floor;
	t_img		*ceilling;
	char		**map;
	int			map_x;
	int			map_y;
	int			player_x;
	int			player_y;
}	t_world;

t_sheet		*new_sheet(char id);
void		del_sheet(t_sheet *del);
t_cub		*new_cub(void);
void		del_cub(t_cub *del);
t_window	*new_window(size_t wdt, size_t hgt, char *title);
void		del_window(t_window *del);
t_img		*new_img(char *name, void *conn, size_t wdt, size_t hgt);
void		del_img(t_img *del);
t_tile		*new_tile(void);
void		del_tile(t_tile *del);
t_sprite	*new_sprite(void);
void		del_sprite(t_sprite *del);
t_world		*new_world(void);
void		del_world(t_world *del);

#endif
