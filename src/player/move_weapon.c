/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** move_weapon.c
*/

#include <math.h>
#include "player.h"
#include "map.h"
#include "enemy.h"
#include "song_manage.h"

static bool is_enemy_touch(player_t *pl, wall_t *weapon,
    wall_t *w_pos, game_assets_t *win)
{
    float max = weapon->weapon->max_dist;
    float add_x = weapon->weapon->tr_size * cosf(pl->angle + X_AXCIS);
    float add_y = weapon->weapon->tr_size * sinf(pl->angle + X_AXCIS);
    sfVector2f p1 = {pl->pos.x + add_x, pl->pos.y + add_y};
    sfVector2f p2 = {pl->pos.x - add_x, pl->pos.y - add_y};

    for (; w_pos != NULL && w_pos->distance < max; w_pos = w_pos->next) {
        if (w_pos->object != IS_ENEMY)
            continue;
        if (point_in_triangle(w_pos->pos1, weapon->pos2, p1, p2)) {
            weapon->pos1 = w_pos->pos1;
            w_pos->enemy->is_touch = true;
            w_pos->enemy->life_to_rm = weapon->weapon->attack;
            weapon->weapon->rect.top = DEF_TEXT_W(weapon->weapon->size.y);
            play_song(win, pl->weapon_name, weapon->pos1);
            return false;
        }
    }
    return break_wall(pl, win, weapon);
}

static void get_all_max(game_assets_t *win, wall_t *weapon)
{
    sfVector2f p = win->entities.player->pos;
    float a = win->entities.player->angle;
    float max = 0.0;

    max = get_max(win, weapon);
    if (max != weapon->weapon->init_max_dist)
        max -= SUS_CHECK_WALL;
    weapon->weapon->max_dist = max;
    weapon->pos2 = (sfVector2f){p.x + max * cosf(a), p.y + max * sinf(a)};
}

bool set_weapon_pos(game_assets_t *win, wall_t *weapon)
{
    static bool anc_attack = false;

    if (weapon == NULL || weapon->weapon == NULL)
        return false;
    if (weapon->weapon->mana_to_rm > win->entities.player->magic) {
        weapon->weapon->is_attacking = false;
        return false;
    }
    if (anc_attack && !weapon->weapon->is_attacking)
        anc_attack = false;
    if (weapon->weapon->is_attacking == false)
        return false;
    if (!anc_attack && weapon->weapon->is_attacking) {
        win->entities.player->magic -= weapon->weapon->mana_to_rm;
        get_all_max(win, weapon);
        anc_attack = true;
        return is_enemy_touch(win->entities.player, weapon,
            win->entities.wall, win);
    }
    return false;
}
