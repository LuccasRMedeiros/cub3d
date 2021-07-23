/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:41:45 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/23 00:02:24 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This is the base header for all the program. Here are the structs, defines  -
** and enums that are meant to be shared to all the modules of this program.
** It also have all the others libraries that are used in this project.
*/

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

# include <libft.h>
# include <math.h>
# include <mlx.h>

# define PI 3.14159265
# define RDR (PI / 180)
# define FOV_ANG (60 * RDR)
# define NORTH (3 * PI / 2)
# define SOUTH (PI / 2)
# define WEST (PI)
# define EAST (2 * PI)
# define TILESIZE 64

# define EXIT 0xff1b
# define FWRD 0x77
# define REAR 0x73
# define RGHT 0x64
# define LEFT 0x61
# define TRGT 0xff53
# define TLFT 0xff51

typedef enum e_axis
{
	X,
	Y
}	t_axis;

typedef enum e_dirs
{
	UPDN,
	LTRT,
}	t_dirs;

typedef enum e_screen_measure
{
	WDT,
	HGT
}	t_measure;

typedef struct s_sheet
{
	char	id;
	bool	is_wall;
	char	*no_face;
	char	*so_face;
	char	*we_face;
	char	*ea_face;
}	t_sheet;

typedef struct s_cub
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

typedef struct s_img
{
	void	*conn;
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		end;
}	t_img;

typedef struct s_wndw
{
	void	*conn;
	void	*wndw;
	int		wdt;
	int		hgt;
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
	int			abs_x;
	int			abs_y;
}	t_world;

typedef struct s_ray
{
	float	ang;
	int		dirs[2];
	float	yo;
	float	xo;
	float	ry;
	float	rx;
	int		map_x;
	int		map_y;
	float	dist;
	int		color;
}	t_ray;

typedef struct s_actor
{
	char	id;
	int		map_x;
	int		map_y;
	float	abs_x;
	float	abs_y;
	float	dir;
	float	delta_x;
	float	delta_xl;
	float	delta_y;
	float	delta_yl;
	t_ray	*rays;
}	t_actor;

typedef struct s_column
{
	float	d_proj;
	float	perp_d;
	int		hgt;
	int		wdt;
	int		org_sy;
	int		end_sy;
	int		color;
}	t_column;

t_sheet		*new_sheet(char id, bool is_wall);
void		del_sheet(t_sheet *del);
t_cub		*new_cub(void);
void		del_cub(t_cub *del);
t_img		*new_img(t_wndw *wndw);
void		del_img(t_img *del);
t_wndw		*new_window(int wdt, int hgt, char *title);
void		del_window(t_wndw *del);
t_tile		*new_tile(t_sheet *tilesheet);
void		del_tile(t_tile *del);
t_sprite	*new_sprite(t_sheet *spritesheet);
void		del_sprite(t_sprite *del);
t_world		*new_world(t_cub *cub);
void		del_world(t_world *del);
t_actor		*new_actor(char id, int pos_x, int pos_y);
void		del_actor(t_actor *del);
t_ray		new_ray(double ang);
t_column	new_column(const t_wndw *wndw, const t_ray *ray, float dir);
float		normalize_angle(float ang);

#endif
