/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** set_labyrinth.c
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

static const break_array_t breakbable[] = {
    {{240, 168}, {240, 200}, W_WOOD},
    {{240, 208}, {240, 240}, W_WOOD},
    {{440, 0}, {440, 40}, W_WOOD},
    {{200, 40}, {232, 0}, W_WOOD},
    {{160, 360}, {200, 320}, W_WOOD},
    {{320, 400}, {360, 360}, W_WOOD}
};

static const add_item_t item_array[] = {
    {{200, 20}, I_MONEY},
    {{160, 20}, I_MONEY},
    {{200, 340}, I_MONEY},
    {{220, 350}, I_MONEY},
    {{340, 340}, I_MONEY},
    {{340, 360}, I_MONEY},
    {{340, 340}, I_MONEY},
    {{180, 170}, I_MONEY},
    {{180, 190}, I_MONEY},
    {{180, 210}, I_MONEY},
    {{180, 230}, I_MONEY},
    {{200, 180}, I_MONEY},
    {{200, 200}, I_MONEY},
    {{200, 220}, I_MONEY}
};

void set_labyrinth(game_assets_t *win, sfVector2f reset)
{
    wall_t *tmp = read_file(ROOM(labyrinth), &win->entities.player->pos);

    if (tmp == NULL)
        return;
    win->shadow_room = true;
    free_wall(win->entities.wall);
    win->entities.wall = tmp;
    if (reset.x != RESET || reset.y != RESET)
        win->entities.player->pos = reset;
    read_file_enemy(ENEMY(labyrinth), win);
    add_all_weapon(win);
    win->room = RM_LABYRINTH;
    add_breakable_array(win, breakbable,
        sizeof(breakbable) / sizeof(break_array_t));
    add_item_array(win, item_array, sizeof(item_array) / sizeof(add_item_t));
    win->entities.player->angle = 0;
    write_a_save(win, win->nb_save);
}
