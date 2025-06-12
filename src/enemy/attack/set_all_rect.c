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

void set_rect_attack(enemy_attack_t *attack, game_assets_t *win)
{
    float time = get_millis(win->csfml.clock);
    int frame = (time - attack->anc_time) * FPS(ATTACK_ENEMY);

    for (; frame > 0; --frame) {
        attack->rect.left = fmodf(attack->rect.left + attack->size.y,
                attack->size.x);
        attack->anc_time = time;
    }
}
