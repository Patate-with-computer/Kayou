/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** move_an_enemy.c
*/

#include <math.h>
#include "window/window_manage.h"
#include "enemy.h"
#include "map.h"
#include "lib.h"
#include "player.h"

static const float speed_en[4] = {
    SPEED_ENEMY - 20, SPEED_ENEMY, 100, 80
};

static const float detect_area[4] = {
    MAX_CHECK_ENEMY, MAX_CHECK_ENEMY + 20, 90, 5000
};

static bool check_walls(game_assets_t *win, sfVector2f new_pos)
{
    wall_t *wall = win->entities.wall;

    for (; wall != NULL; wall = wall->next) {
        if (wall->object != IS_WALL)
            continue;
        if (distance_to_wall(new_pos, wall) <= MAX_DISTANCE_WALL)
            return false;
    }
    return true;
}

static sfVector2f check_wall(game_assets_t *win, wall_t *enemy)
{
    float speed = SPEED(speed_en[enemy->texture.text_nb],
        get_millis(win->csfml.clock), enemy->enemy->anc_time_move);
    float angle = enemy->enemy->angle;

    if (win->restart_clock)
        speed = 0;
    if (get_distance(win->entities.player->pos, enemy->pos1) <
            detect_area[enemy->texture.text_nb])
        angle = win->entities.player->angle + M_PI;
    for (size_t i = 0; i < 180; ++i) {
        if (check_walls(win, (sfVector2f){enemy->pos1.x + cosf(angle) * speed,
                enemy->pos1.y + sinf(angle) * speed})) {
            enemy->enemy->angle = angle;
            return (sfVector2f){cosf(angle) * speed, sinf(angle) * speed};
        }
        angle += 2.0 * M_PI / 180.0f;
    }
    return (sfVector2f){0, 0};
}

void move_an_enemy(game_assets_t *win, wall_t *enemy)
{
    sfVector2f to_add = {0};

    if (!win->is_paused) {
        to_add = check_wall(win, enemy);
        enemy->pos1.x += to_add.x;
        enemy->pos1.y += to_add.y;
    }
    enemy->enemy->anc_time_move = get_millis(win->csfml.clock);
}
