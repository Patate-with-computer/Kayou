/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** set_labyrinth.c
*/

#include "player.h"
#include "enemy.h"
#include "file_manage.h"
#include "map.h"
#include "ground_evt.h"
#include "texture_pack.h"
#include "items.h"
#include "save_manage.h"

static const break_array_t breakable[] = {
    {{20, 40}, {20, 80}, W_WOOD},
    {{80, 680}, {112, 680}, W_WOOD},
    {{120, 728}, {120, 800}, W_WOOD},
    {{160, 608}, {160, 640}, W_WOOD},
    {{560, 680}, {560, 720}, W_WOOD},
    {{560, 520}, {600, 520}, W_WOOD},
    {{240, 360}, {240, 400}, W_WOOD},
    {{320, 280}, {360, 280}, W_WOOD},
    {{440, 360}, {440, 400}, W_WOOD},
    {{320, 480}, {360, 480}, W_WOOD},
    {{520, 128}, {520, 200}, W_WOOD},
    {{160, 560}, {192, 560}, W_WALL_2}
};

static const add_item_t item_array[] = {
    {{260, 20}, I_LIFE},
    {{660, 20}, I_LIFE},
    {{100, 380}, I_LIFE},
    {{420, 200}, I_LIFE},
    {{240, 700}, I_LIFE},
    {{420, 700}, I_LIFE},
    {{260, 580}, I_LIFE},
    {{240, 740}, I_LIFE},
    {{540, 780}, I_LIFE},
    {{660, 700}, I_LIFE},
    {{540, 780}, I_LIFE},
    {{660, 700}, I_LIFE},
    {{540, 780}, I_LIFE},
    {{660, 700}, I_LIFE},
    {{20, 780}, I_MONEY},
    {{20, 780}, I_MONEY},
    {{20, 760}, I_MANA},
    {{60, 780}, I_MONEY},
    {{60, 760}, I_MANA},
    {{100, 780}, I_MONEY},
    {{100, 760}, I_MANA},
    {{220, 540}, I_MONEY},
    {{240, 540}, I_MONEY},
    {{260, 540}, I_MONEY},
    {{220, 540}, I_MONEY},
    {{240, 540}, I_MONEY},
    {{260, 540}, I_MONEY},
    {{220, 540}, I_MONEY},
    {{240, 540}, I_MONEY},
    {{260, 540}, I_MONEY},
    {{220, 540}, I_MONEY},
    {{240, 540}, I_MONEY},
    {{260, 540}, I_MONEY},
    {{220, 540}, I_MONEY},
    {{240, 540}, I_MONEY},
    {{260, 540}, I_MONEY},
    {{220, 540}, I_MONEY},
    {{240, 540}, I_MONEY},
    {{260, 540}, I_MONEY},
    {{220, 540}, I_MONEY},
    {{240, 540}, I_MONEY},
    {{260, 540}, I_MONEY},
    {{220, 540}, I_MONEY},
    {{240, 540}, I_MONEY},
    {{260, 540}, I_MONEY},
    {{220, 540}, I_MONEY},
    {{240, 540}, I_MONEY},
    {{260, 540}, I_MONEY},
    {{220, 540}, I_MONEY},
    {{240, 540}, I_MONEY},
    {{260, 540}, I_MONEY},
    {{220, 540}, I_MONEY},
    {{240, 540}, I_MONEY},
    {{260, 540}, I_MONEY},
    {{640, 460}, I_MANA},
    {{660, 460}, I_LIFE},
    {{640, 460}, I_MANA},
    {{660, 460}, I_LIFE},
    {{320, 360}, I_MONEY},
    {{340, 360}, I_MANA},
    {{400, 420}, I_MONEY},
    {{420, 420}, I_MANA},
    {{320, 360}, I_MONEY},
    {{340, 360}, I_MANA},
    {{400, 420}, I_MONEY},
    {{420, 420}, I_MANA}
};

void set_hell_room(game_assets_t *win, sfVector2f reset)
{
    wall_t *tmp = read_file(ROOM(hell_room), &win->entities.player->pos);

    if (tmp == NULL)
        return;
    win->shadow_room = true;
    free_wall(win->entities.wall);
    win->entities.wall = tmp;
    if (reset.x != RESET || reset.y != RESET)
        win->entities.player->pos = reset;
    read_file_enemy(ENEMY(hell_room), win);
    add_all_weapon(win);
    win->room = RM_HELL_ROOM;
    add_breakable_array(win, breakable,
        sizeof(breakable) / sizeof(break_array_t));
    add_item_array(win, item_array, sizeof(item_array) / sizeof(add_item_t));
    write_a_save(win, win->nb_save);
}
