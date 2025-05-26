/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** move_attack.c
*/

#include <math.h>
#include "player.h"
#include "enemy.h"
#include "window_manage.h"
#include "lib.h"
#include "map.h"

static bool check_walls(sfVector2f add, game_assets_t *win)
{
    for (wall_t *head = win->entities.wall; head != NULL; head = head->next) {
        if (head->object != IS_WALL)
            continue;
        if (distance_to_wall(add, head) <= MIN_DIST_CHECK_ATTACK)
            return false;
    }
    return true;
}

static bool check_remove_wall(wall_t *attack, game_assets_t *win,
    sfVector2f add)
{
    if (get_distance(win->entities.player->pos, attack->pos1) <=
            MIN_DIST_CHECK_ATTACK) {
        win->entities.player->life -= attack->enemy_attack->life_to_rm;
        remove_wall(&win->entities.wall, attack);
        return false;
    }
    if (check_walls(add, win) == false ||
            get_distance(attack->enemy_attack->init_pos, attack->pos1) >=
                attack->enemy_attack->max_dist) {
        remove_wall(&win->entities.wall, attack);
        return false;
    }
    return true;
}

static wall_t *move_attack(wall_t *attack, game_assets_t *win)
{
    float speed = SPEED(attack->enemy_attack->speed,
        get_millis(win->csfml.clock), attack->enemy_attack->anc_time_move);
    sfVector2f add = {cosf(attack->enemy_attack->angle) * speed,
        sinf(attack->enemy_attack->angle) * speed};
    wall_t *tmp = attack->next;

    add.x += attack->pos1.x;
    add.y += attack->pos1.y;
    if (!check_remove_wall(attack, win, add))
        return tmp;
    attack->pos1 = add;
    return attack;
}

void move_all_attack(game_assets_t *win)
{
    for (wall_t *head = win->entities.wall; head != NULL; head = head->next) {
        if (head->object != IS_ATTACK)
            continue;
        if (!win->is_paused)
            head = move_attack(head, win);
        if (head == NULL)
            break;
        if (head->object == IS_ATTACK)
            head->enemy_attack->anc_time_move = get_millis(win->csfml.clock);
    }
}
