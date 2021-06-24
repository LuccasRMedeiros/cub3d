/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:55:02 by lrocigno          #+#    #+#             */
/*   Updated: 2021/06/24 11:02:51 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** cub3d_error treats all the possible syntax errors when excuting (or trying  -
** to) the program.
** Such syntax errors are related to the cub file and the program call.
*/

#ifndef CUB3D_ERROR_H
# define CUB3D_ERROR_H

# include <cub3d_structs.h>

# define PLAYER "NSWE"
# define INNER "02NSWE"
# define VLCHR " 012NSWE"

void	error_msg(const char *msg, const char *obj);
void	do_nothing(void);
bool	is_first_def(void *data, const char *p_name, int ruler);
bool	is_map_pattern(const char *line);
bool	validate_color(char **rgb, char *area);
int		validate_cubfile(char *path);
bool	validate_map(t_cub *cub);
bool	validate_player_pos(t_cub *cub);
bool	validate_res(char **values);
bool	validate_texture(char *path, char *where);
void	wrong_order(t_cub *cub);

#endif
