/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:55:02 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/22 15:14:03 by lrocigno         ###   ########.fr       */
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

#endif
