/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:41:45 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/31 19:01:26 by lrocigno         ###   ########.fr       */
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

#include <stdlib.h>

# define PI 3.14159265
# define TPI 6.2831853
# define RDR 0.0174532925
# define FOV_ANG 1.04719755
# define NORTH 4.712388975
# define SOUTH 1.570796325
# define WEST 3.14159265
# define EAST 6.2831853
# define TILESIZE 64

# define EXIT 0xff1b
# define FWRD 0x77
# define REAR 0x73
# define RGHT 0x64
# define LEFT 0x61
# define TRGT 0xff53
# define TLFT 0xff51

typedef enum
{
    X,
    Y
}   e_axis;

typedef enum
{
    UPDN,
    LTRT,
}   e_dirs;

typedef enum
{
    WDT,
    HGT
}   e_measure;

typedef enum
{
    SMP,
    TEX
}   e_img_type;

typedef struct
{
    char    id;
    bool    is_wall;
    char    *no_face;
    char    *so_face;
    char    *we_face;
    char    *ea_face;
}   st_sheet;

typedef struct
{
    int     status;
    bool    save;
    int     res[2];
    st_sheet *tilesheet;
    st_sheet *spritesheet;
    int     f_color[3];
    int     c_color[3];
    char    *pre_lyt;
    char    **layout;
    int     map_axis[2];
    int     player_pos[2];
}   st_cub;

typedef struct
{
    void    *conn;
    void    *img;
    int     *addr;
    int     wdt;
    int     hgt;
    int     bpp;
    int     l_len;
    int     end;
}   st_img;

typedef struct
{
    void    *conn;
    void    *wndw;
    int     wdt;
    int     hgt;
}   st_wndw;

typedef struct
{
    char    id;
    st_img   *wall_no;
    st_img   *wall_so;
    st_img   *wall_we;
    st_img   *wall_ea;
}   st_tile;

typedef struct
{
    char    id;
    st_img   *sprite;
}   st_sprite;

typedef struct
{
    char    id;
    float   ang;
    int     dirs[2];
    float   yo;
    float   xo;
    float   ry;
    float   rx;
    int     map_x;
    int     map_y;
    float   dist;
}   st_ray;

typedef struct
{
    float   p_rl_ang;
    float   s_rl_ang;
    float   dist;
    int     p_rl_x;
    int     wdt;
    int     hgt;
    int     org_sy;
    int     end_sy;
    int     org_sx;
    int     end_sx;
    bool    visible;
}   st_obj;

typedef struct
{
    char    id;
    st_img   *texture;
    int     map_x;
    int     map_y;
    int     abs_x;
    int     abs_y;
    st_obj   obj;
}   st_static_obj;

typedef struct
{
    st_tile      *tileset;
    st_sprite    *spriteset;
    int         floor;
    int         ceilling;
    char        **map;
    int         map_x;
    int         map_y;
    int         abs_x;
    int         abs_y;
    int         n_sprites;
}   st_world;

typedef struct
{
    float   d_proj;
    float   perp_d;
    int     hgt;
    int     org_sy;
    int     end_sy;
    int     ox;
    st_img   *texture;
}   st_column;

typedef struct
{
    char    id;
    int     map_x;
    int     map_y;
    int     abs_x;
    int     abs_y;
    float   dir;
    float   d_proj;
    float   delta_x;
    float   delta_xl;
    float   delta_y;
    float   delta_yl;
    int     move_frrr;
    int     move_lfrt;
    int     vsn_turn;
    st_ray   *rays;
}   st_actor;

st_sheet         *new_sheet(char id, bool is_wall);
void            del_sheet(st_sheet *del);
st_cub           *new_cub(void);
void            del_cub(st_cub *del);
st_img           *new_img(st_wndw *wndw, int wdt, int hgt, char *file_path);
void            del_img(st_img *del);
st_wndw          *new_window(int wdt, int hgt, char *title);
void            del_window(st_wndw *del);
st_tile          *new_tile(st_sheet *tilesheet, st_wndw *wndw);
void            del_tile(st_tile *del);
st_sprite        *new_sprite(st_sheet *spritesheet, st_wndw *wndw);
void            del_sprite(st_sprite *del);
st_world         *new_world(st_cub *cub, st_wndw *wndw);
void            del_world(st_world *del);
st_actor         *new_actor(char id, st_wndw *wndw, int pos_x, int pos_y);
void            del_actor(st_actor *del);
st_ray           new_ray(char id, double ang);
st_column        *new_column(st_wndw *wndw, st_world *wrld, st_ray *ray, float dir);
void            del_column(st_column *del);
st_static_obj    *list_static_obj(st_world *wrld);
st_obj           new_obj(st_wndw *wndw, st_actor *p, st_static_obj obj);
void            del_static_obj(st_static_obj *del);
float           normalize_angle(float ang);
int             color_picker(int rgb[3]);

#endif
