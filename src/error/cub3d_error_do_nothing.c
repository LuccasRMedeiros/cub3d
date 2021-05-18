/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error_do_nothing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:26:17 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/18 11:02:08 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Doesn't do anything, really.
**
**         ____
**        /    |
**       /    /
**      /    /
**     /     |
**    /      |___________
**   |                   \
**   |           ________|
**	 |                    \
**	 |            ________/
**   |                   |
**   |            _______/
**   |                 |
**   \_________________/ 
**
*/

#include "cub3d_error.h"

void	do_nothing(void);
{
	printf("\e[0;31m");
	printf("This function exists to permit the program to compile even when ");
	printf("another function that is vital for the program work properly was ");
	printf("not implemented yet.\n");
	printf("So, of course this is a placeholder, and only should be called ");
	printf("to permit debugging and development ongoing. If it is not the ");
	printf("case, find this function reference and remove it.\e[0m\n");
}
