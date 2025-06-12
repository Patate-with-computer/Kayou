/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** set_all_rect.c
*/

#include <math.h>
#include "enemy.h"
#include "lib.h"
#include "window/window_manage.h"

void set_rect(enemy_t *enemy, game_assets_t *win)
{
    float time = get_millis(win->csfml.clock);
    float nbr_frame = enemy->size.x / (enemy->size.y / 3.0);
    int frame = (time - enemy->anc_time) * FPS(ANIMATION) * nbr_frame;

    for (; frame > 0; --frame) {
        enemy->rect.left = fmodf(enemy->rect.left + enemy->size.y / NB_TEXT,
                enemy->size.x);
        enemy->anc_time = time;
    }
}
