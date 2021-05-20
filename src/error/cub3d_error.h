/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:55:02 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/20 15:26:59 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** cub3d_error treats all the possible syntax errors when excuting (or trying  -
** to) the program.
** Such syntax errors are related to the cub file and the program call.
*/

#ifndef CUB3D_ERROR_H
# define CUB3D_ERROR_H

# include <libft.h>

void	error_msg(char *msg, char *action);
void	do_nothing(void);
bool	check_invalid_res(char **values);
bool	check_invalid_texture(char *path, char *where);
bool	check_invalid_color(char **rgb, char *area);
bool	check_invalid_layout(const char *layout);

#endif
