/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_print_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 20:36:39 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/21 23:29:52 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Print the map and where the rays are hitting.
*/

void print_map(t_world *wrld, t_actor *player, int n_rays) {
	int n_ray;
	int x, y;

    for (y = 0; y < wrld->map_y; ++y) {
		for (x = 0; x <= wrld->map_x; ++x) {
			n_ray = 0;
			while (n_ray < n_rays) {
				if (x == player->rays[n_ray].map_x && y == player->rays[n_ray].map_y) {
					if (player->rays[n_ray].color == 0xFF0000) {
						printf("\e[1;31m%c\e[0m", wrld->map[y][x]);
					} else {
						printf("\e[0;31m%c\e[0m", wrld->map[y][x]);
					}
					++x;
				}
				++n_ray;
			}
			if (x == player->map_x && y == player->map_y) {
				printf("\e[1;34m%c\e[0m", 'P');
			}
			else if (ft_strhvchr("NSWE", wrld->map[y][x])) {
				printf("0");
			}
			else if (x == wrld->map_x) {
				printf("\n");
			}
			else {
				printf("%c", wrld->map[y][x]);
			}		
		}
    }
	printf("\n player abs_x: %f | player abs_y: %f | player direction: %f \n", player->abs_x, player->abs_y, player->dir);
	printf("\n player map_x: %i | player map_y: %i\n\n", player->map_x, player->map_y);
}
