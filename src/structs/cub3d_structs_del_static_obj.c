/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs_del_static_obj.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:56:51 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/25 19:23:38 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_structs.h"

/*
** Destroy the entire static_actor list. In future changes it will destroy only-
**  one.
*/

void	del_static_obj(t_static_obj *del)
{
	free(del);
}
