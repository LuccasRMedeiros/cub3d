/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:55:02 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/23 12:09:53 by lrocigno         ###   ########.fr       */
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

void		error_msg(char *msg, char *obj);
void		do_nothing(void);

#endif
