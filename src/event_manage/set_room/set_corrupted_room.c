/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** set_corrupted_room.c
*/

#include <math.h>
#include "player.h"
#include "enemy.h"
#include "file_manage.h"
#include "map.h"
#include "ground_evt.h"
#include "texture_pack.h"
#include "items.h"
#include "save_manage.h"
#include "screen_text.h"

static const break_array_t breakbable[] = {
    {{40, 680}, {80, 680}, W_WOOD},
    {{480, 520}, {520, 520}, W_WOOD},
    {{0, 48}, {0, 80}, W_WOOD},
    {{40, 280}, {78, 240}, W_WOOD},
    {{360, 360}, {360, 400}, W_WOOD},
    {{360, 240}, {400, 240}, W_WOOD},
    {{480, 240}, {520, 200}, W_WOOD},
    {{180, 280}, {180, 288}, W_WOOD},
    {{240, 440}, {248, 440}, W_WOOD},
    {{440, 0}, {440, 40}, W_WOOD},
    {{80, 400}, {120, 440}, W_WALL_2},
    {{120, 520}, {160, 480}, W_WALL_2}
};

static const add_item_t item_array[] = {
    {{40, 480}, I_MONEY},
    {{40, 480}, I_MONEY},
    {{40, 480}, I_MONEY},
    {{60, 460}, I_LIFE},
    {{620, 500}, I_BARIL},
    {{80, 520}, I_MONEY},
    {{80, 520}, I_MONEY},
    {{80, 520}, I_MONEY},
    {{100, 540}, I_LIFE},
    {{100, 540}, I_LIFE},
    {{100, 540}, I_LIFE},
    {{500, 20}, I_LIFE}
};

static const add_pnj_t pnj_array[] = {
    {{480, 20}, I_PNJ3, plank}
};

void set_corrupted_room(game_assets_t *win, sfVector2f reset)
{
    wall_t *tmp = read_file(ROOM(corrupted_room), &win->entities.player->pos);

    if (tmp == NULL)
        return;
    win->is_brume = true;
    win->shadow_room = false;
    free_wall(win->entities.wall);
    win->entities.wall = tmp;
    if (reset.x != RESET || reset.y != RESET)
        win->entities.player->pos = reset;
    read_file_enemy(ENEMY(corrupted_room), win);
    add_all_weapon(win);
    win->room = RM_CORRUPTED_ROOM;
    add_breakable_array(win, breakbable,
        sizeof(breakbable) / sizeof(break_array_t));
    add_item_array(win, item_array, sizeof(item_array) / sizeof(add_item_t));
    add_pnj_array(win, pnj_array, sizeof(pnj_array) / sizeof(add_pnj_t));
    win->entities.player->angle = 0;
    write_a_save(win, win->nb_save);
}
