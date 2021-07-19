/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw_print_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 20:36:39 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/18 14:43:20 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_draw.h"

/*
** Print the map and where the rays are hitting.
*/

void print_map(t_world *wrld, t_actor *player) {
	int n_ray;
	int x, y;

    for (y = 0; y < wrld->map_y; ++y) {
		for (x = 0; x <= wrld->map_x; ++x) {
			n_ray = 0;
			while (n_ray < 60) {
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
	printf("\n player x: %i | player y: %i | player direction: %f \n\n", player->map_x, player->map_y, player->dir);
}
