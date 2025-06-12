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
#include "screen_text.h"

static const break_array_t breakbable[] = {
    {{96, 8}, {96, 64}, W_WOOD},
    {{64, 72}, {64, 128}, W_WOOD},
    {{80, 136}, {80, 192}, W_WOOD},
    {{80, 200}, {80, 240}, W_WOOD},
};

static const add_item_t item_array[] = {
    {{64, 256}, I_MONEY},
    {{80, 256}, I_LIFE},
    {{90, 256}, I_MANA},
    {{106, 256}, I_MONEY},
    {{64, 264}, I_MONEY},
    {{80, 264}, I_LIFE},
    {{90, 264}, I_MANA},
    {{106, 264}, I_MONEY},
    {{64, 272}, I_MONEY},
    {{80, 272}, I_LIFE},
    {{90, 272}, I_MANA},
    {{106, 272}, I_MONEY},
};

static const add_pnj_t pnj_array[] = {
    {{70, 55}, I_PNJ, break_the_wall},
    {{75, 115}, I_PNJ2, there_is_shadow},
    {{70, 180}, I_PNJ3, there_is_fog},
    {{90, 230}, I_ENEMY, there_is_item},
    {{128, 256}, I_PNJ3, there_is_enemy}
};

void set_demo(game_assets_t *win, sfVector2f reset)
{
    wall_t *tmp = read_file(ROOM(room_demo), &win->entities.player->pos);

    if (tmp == NULL)
        return;
    free_wall(win->entities.wall);
    win->entities.wall = tmp;
    win->entities.player->angle = 0.0f;
    win->is_brume = false;
    win->shadow_room = false;
    if (reset.x != RESET || reset.y != RESET)
        win->entities.player->pos = reset;
    add_all_weapon(win);
    read_file_enemy(ENEMY(room_demo1), win);
    add_breakable_array(win, breakbable,
        sizeof(breakbable) / sizeof(break_array_t));
    add_item_array(win, item_array, sizeof(item_array) / sizeof(add_item_t));
    add_pnj_array(win, pnj_array, sizeof(pnj_array) / sizeof(add_pnj_t));
    win->room = RM_DEMO;
    write_a_save(win, win->nb_save);
}
