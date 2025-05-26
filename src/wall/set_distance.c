/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** set_distance.c
*/

#include "player.h"
#include "map.h"
#include "enemy.h"
#include "items.h"
#include "song_manage.h"

static void set_a_distance_to_a_wall(player_t *player, wall_t *cpy,
    game_assets_t *win)
{
    if (cpy == NULL)
        return;
    if (cpy->object == IS_WALL)
        cpy->distance = distance_to_wall(player->pos, cpy);
    if (cpy->object == IS_ENEMY) {
        cpy->distance = get_distance(player->pos, cpy->pos1);
        set_rect(cpy->enemy, win);
    }
    if (cpy->object == IS_ATTACK) {
        cpy->distance = get_distance(player->pos, cpy->pos1);
        set_rect_attack(cpy->enemy_attack, win);
    }
}

void set_all_distance(game_assets_t *win, player_t *player, wall_t *wall)
{
    wall_t *weapon = player->weapon[player->weapon_name];

    if (weapon != NULL && !win->is_paused) {
        set_rect_weapon(weapon->weapon, win);
        weapon->distance = get_distance(player->pos, weapon->pos1);
        if (set_weapon_pos(win, weapon))
            return;
    }
    for (wall_t *cpy = wall; cpy != NULL; cpy = cpy->next) {
        set_a_distance_to_a_wall(player, cpy, win);
        if (cpy->object == IS_ITEM)
            cpy = check_item(win, player, cpy);
        if (cpy == NULL)
            break;
    }
}
