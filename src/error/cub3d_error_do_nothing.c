/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_error_do_nothing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:26:17 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/09 10:32:05 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** It is a placeholder. Prints a blue cube in stdout
** Can be called to help structuring a program part a keep compiling it.
*/

#include "cub3d_error.h"

void	do_nothing(int args, ...)
{
	printf("\e[1;34m\n");
	printf("	                          ***\n");
	printf("	                       ***   ***\n");
	printf("	                    ***         ***\n");
	printf("	                 ***               ***\n");
	printf("	              ***                     ***\n");
	printf("	              |++***               ***++|\n");
	printf("	              |#+++:***         ***:+++#|\n");
	printf("	              |#+++:...***   ***...:+++#|\n");
	printf("	              |#+++::..   ***   ..::+++#|\n");
	printf("	              |#+++:::..   |   ..:::+++#|\n");
	printf("	              |#+++:::..   |   ..:::+++#|\n");
	printf("	              ***++:::...  |  ...:::++***\n");
	printf("	                 ***+:...  |  ...:+***\n");
	printf("	                    ***::..|..::***\n");
	printf("	                       ***+|+***\n");
	printf("	                          ***\n");
	printf("\e[0m\n");
	args = 0;
}
