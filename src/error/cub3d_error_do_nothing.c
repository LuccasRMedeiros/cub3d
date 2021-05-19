/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error_do_nothing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:26:17 by lrocigno          #+#    #+#             */
/*   Updated: 2021/05/19 15:16:28 by lrocigno         ###   ########.fr       */
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

void	do_nothing(void)
{
	printf("\e[0;32mHey it appears that you found an easteregg!\e[0m\n");
	printf("\e[0;31mJust kiding, there are no eastereggs here\e[0m\n\n");
	printf("                         ***\n");
	printf("                      ***   ***\n");
	printf("                   ***         ***\n");
	printf("                ***               ***\n");
	printf("             ***                     ***\n");
	printf("             |#+***               ***++|\n");
	printf("             |#+++:***         ***:::++|\n");
	printf("             |#+++:::.***   ***...:::++|\n");
	printf("             |#+++:::... ***   ...:::++|\n");
	printf("             |#+++:::...  |    ...:::++|\n");
	printf("             |#+++:::...  |    ...:::++|\n");
	printf("             ***++:::...  |    ...:::***\n");
	printf("                ***::...  |    ...***\n");
	printf("                   ***..  |    ***\n");
	printf("                      *** | ***\n");
	printf("                         ***\n\n");
}
