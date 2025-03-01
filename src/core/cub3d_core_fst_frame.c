/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_core_fst_frame.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 17:51:56 by lrocigno          #+#    #+#             */
/*   Updated: 2021/07/31 23:06:34 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_core.h"

/**
 * Basicaly this is a copy of update_frame, but receive a the "save" argument  -
 * to take a screenshot (or not).
 *
 * TODO: It is possible to delegate the resposability to save the take the
 * screenshot to the update_frame function.
 */
void fst_frame(st_program *prog, int save)
{
    st_img *frame;

    frame = new_img(prog->wndw, prog->wndw->wdt, prog->wndw->hgt, NULL);

    if (prog->player->move_frrr || prog->player->move_lfrt)
        navigate(prog->wrld, prog->player);

    if (prog->player->vsn_turn)
        player_turn(prog->player);

    ray_cast(prog->wrld, prog->player, prog->wndw->wdt);
    draw_background(frame, prog->wndw, prog->wrld);
    render_projection(frame, prog->wrld, prog->wndw, prog->player);

    if (prog->sprite_list)
    {
        analyze_sprites(prog->wndw, prog->wrld,
            prog->player, prog->sprite_list);
        render_sprites(frame, prog->sprite_list, prog->wrld->n_sprites);
    }

    mlx_put_image_to_window(prog->wndw->conn,
        prog->wndw->wndw, frame->img, 0, 0);

    if (save)
        screenshot(frame);

    del_img(frame);

    free(prog->player->rays);
}
