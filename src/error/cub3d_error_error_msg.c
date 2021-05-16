/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error_error_msg.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:33:29 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/16 18:53:05 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This function is responsible to emit the error mesages.
** It cames with a predefined template, but in order to use this is important  -
** inform two things to the function, what happened and where or with what.
** msg is what happened
** obj refers to where the error were found during the compilation.
** To write a break line in the msg string is unecessary as the function       -
** automatically does this after print the error message.
*/

#include "cub3d_error.h"

void	error_msg(char *msg, char *obj)
{
	ft_fprintf(2, "\e[0;31mA problem has ocurred with/at %s: \e[0m\n", obj);
	ft_fprintf(2, msg);
	write(2, '\n', 1);
}
