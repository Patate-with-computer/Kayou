/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** project_pt.c
*/

#include <math.h>
#include "window_manage.h"
#include "player.h"
#include "map.h"

sfVector3f project_pt(game_assets_t *win, sfVector2f wall_pos,
    is_printable_t *pr)
{
    player_t *player = win->entities.player;
    sfVector2f player_pos = player->pos;
    float angle = player->angle;
    sfVector2f dpos = {wall_pos.x - player_pos.x, wall_pos.y - player_pos.y};
    sfVector2f pos = {
        dpos.x * cosf(angle + X_AXCIS) + dpos.y * sinf(angle + X_AXCIS),
        dpos.x * sinf(angle + X_AXCIS) - dpos.y * cosf(angle + X_AXCIS)
    };

    player->focal = (win->size.x / 2.0f) / (tanf(win->fov / 2.0f));
    *pr = PRINTABLE;
    if (pos.y <= MIN_Y)
        *pr = NOT_PRINTABLE;
    return (sfVector3f) {
        (pos.x * player->focal) / pos.y,
        win->scale.y * (player->focal / (pos.y * 0.1)),
        (SIZE_WALL * player->focal) / pos.y
    };
}
