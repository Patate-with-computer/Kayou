/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** set_intro.c
*/

#include "player.h"
#include "enemy.h"
#include "file_manage.h"
#include "map.h"
#include "ground_evt.h"
#include "texture_pack.h"
#include "items.h"
#include "save_manage.h"

static const break_array_t breakbable[] = {
    {{32, 32}, {96, 96}, W_WOOD},
    {{160, 96}, {96, 160}, W_WOOD},
    {{160, 192}, {96, 256}, W_WOOD},
    {{32, 256}, {96, 328}, W_WOOD},
    {{128, 288}, {160, 288}, W_WOOD}
};

static const add_item_t item_array[] = {
    {{248, 8}, I_MONEY},
    {{264, 8}, I_LIFE},
    {{280, 8}, I_MANA},
    {{264, 24}, I_MONEY},
    {{280, 24}, I_MONEY},
    {{280, 40}, I_LIFE},
    {{220, 200}, I_BARIL},
    {{220, 100}, I_BARIL}
};

void set_diag_map(game_assets_t *win, sfVector2f reset)
{
    wall_t *tmp = read_file(ROOM(diag_map), &win->entities.player->pos);

    if (tmp == NULL)
        return;
    free_wall(win->entities.wall);
    win->entities.wall = tmp;
    win->shadow_room = false;
    win->is_brume = false;
    if (reset.x != RESET || reset.y != RESET)
        win->entities.player->pos = reset;
    read_file_enemy(ENEMY(diag_map), win);
    add_all_weapon(win);
    add_breakable_array(win, breakbable,
        sizeof(breakbable) / sizeof(break_array_t));
    add_item_array(win, item_array, sizeof(item_array) / sizeof(add_item_t));
    win->room = RM_DIAGMAP;
    write_a_save(win, win->nb_save);
}
