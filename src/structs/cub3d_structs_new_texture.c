/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_new_texture.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:24:23 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/23 20:37:10 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Create a t_texture instance from a informed relative file path.
*/

t_texture	*new_texture(void *conn, char *file_path);
{
	t_texture	*new;

	new->file = mlx_xpm_file_to_image(conn, file_path, &new->wdt, &new->hgt);
	return (new);
}
