/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** lock.c
*/

#include <math.h>
#include "player.h"
#include "enemy.h"
#include "map.h"
#include "event_manage.h"

static wall_t *get_enemy_lock(game_assets_t *win)
{
    wall_t *enemy = win->entities.wall;

    for (; enemy != NULL; enemy = enemy->next) {
        if (enemy->object != IS_ENEMY)
            continue;
        break;
    }
    return enemy;
}

static void lock_the_camera(game_assets_t *win, bool lock)
{
    sfVector2f p_pos = win->entities.player->pos;
    sfVector2f e_pos = {0.0, 0.0};
    sfVector2f p = {0.0, 0.0};

    if (win->entities.player->wall_to_lock == NULL)
        return;
    e_pos = win->entities.player->wall_to_lock->pos1;
    if (lock && get_distance(e_pos, p_pos) <= 70.0f) {
        p = (sfVector2f){e_pos.x - p_pos.x, e_pos.y - p_pos.y};
        win->entities.player->angle = atan2f(p.y, p.x);
    }
}

void set_lock_wall(game_assets_t *win)
{
    static bool prev_lock = false;
    bool lock = get_joy_button(0, BUTTON_L2) ||
        sfMouse_isButtonPressed(sfMouseRight);

    if (lock && !prev_lock) {
        win->entities.player->wall_to_lock = get_enemy_lock(win);
        prev_lock = true;
    }
    if (!lock && prev_lock)
        prev_lock = false;
    lock_the_camera(win, lock);
}
