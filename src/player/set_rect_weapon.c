/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** set_rect_weapon.c
*/

#include <math.h>
#include "window/window_manage.h"
#include "player.h"
#include "lib.h"
#include "enemy.h"
#include "map.h"

static void reset_attack(wall_t *wall)
{
    for (; wall != NULL; wall = wall->next) {
        if (wall->object != IS_ENEMY)
            continue;
        wall->enemy->is_touch = false;
    }
}

void set_rect_weapon(weapon_t *weapon, game_assets_t *win)
{
    float time = get_millis(win->csfml.clock);
    int frame = (time - weapon->anc_time) * FPS(ATTACK);

    for (; weapon->is_attacking && frame > 0; --frame) {
        weapon->rect.left += weapon->size.y / NB_TEXT_WEAPON;
        if (weapon->rect.left >= weapon->size.x) {
            weapon->rect.left = 0.0;
            weapon->is_attacking = false;
            reset_attack(win->entities.wall);
        }
        weapon->anc_time = time;
    }
    if (weapon->is_attacking == false)
        weapon->anc_time = time;
}
