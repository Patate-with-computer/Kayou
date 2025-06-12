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
    {{160, 160}, {128, 192}, W_WOOD},
    {{288, 320}, {288, 352}, W_WOOD},
    {{48, 224}, {48, 256}, W_WALL_1},
    {{256, 96}, {256, 128}, W_WOOD},
    {{256, 96}, {224, 96}, W_WOOD},
    {{224, 128}, {256, 128}, W_WOOD},
    {{224, 128}, {224, 96}, W_WOOD},
    {{160, 256}, {160, 288}, W_WOOD},
    {{160, 256}, {128, 256}, W_WOOD},
    {{128, 288}, {160, 288}, W_WOOD},
    {{128, 288}, {128, 256}, W_WOOD},
    {{48, 288}, {48, 320}, W_WALL_1}
};

static const add_item_t item_array[] = {
    {{232, 104}, I_MONEY},
    {{232, 120}, I_MONEY},
    {{248, 104}, I_MONEY},
    {{248, 120}, I_MONEY},
    {{228, 220}, I_BARIL},
    {{152, 264}, I_MONEY},
    {{152, 280}, I_MONEY},
    {{136, 264}, I_MONEY},
    {{136, 280}, I_MONEY},
    {{32, 304}, I_LIFE},
    {{32, 320}, I_MANA},
    {{32, 336}, I_MONEY},
    {{16, 304}, I_LIFE},
    {{16, 320}, I_MANA},
    {{16, 336}, I_MONEY},
    {{150, 12}, I_FLOWER},
    {{150, 32}, I_FLOWER},
    {{130, 12}, I_FLOWER},
    {{150, 100}, I_BLOOD2},
    {{150, 80}, I_BRICK},
    {{150, 60}, I_BLOOD2},
    {{150, 120}, I_FLOWER},
    {{150, 140}, I_BRICK}
};

static const add_pnj_t pnj_array[] = {
    {{100, 50}, I_PNJ, intro_pnj},
    {{70, 300}, I_ENEMY, intro_pnj_enemy},
    {{250, 320}, I_PNJ2, intro_command}
};

void set_intro(game_assets_t *win, sfVector2f reset)
{
    wall_t *tmp = read_file(ROOM(intro), &win->entities.player->pos);

    if (tmp == NULL)
        return;
    free_wall(win->entities.wall);
    win->entities.wall = tmp;
    win->is_brume = false;
    win->shadow_room = false;
    if (reset.x != RESET || reset.y != RESET)
        win->entities.player->pos = reset;
    read_file_enemy(ENEMY(intro), win);
    add_all_weapon(win);
    add_breakable_array(win, breakbable,
        sizeof(breakbable) / sizeof(break_array_t));
    add_item_array(win, item_array, sizeof(item_array) / sizeof(add_item_t));
    add_pnj_array(win, pnj_array, sizeof(pnj_array) / sizeof(add_pnj_t));
    win->room = RM_INTRO;
    write_a_save(win, win->nb_save);
}
