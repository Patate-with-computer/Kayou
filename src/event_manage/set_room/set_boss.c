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

static const add_item_t item_array[] = {
    {{16, 48}, I_LIFE},
    {{16, 64}, I_LIFE},
    {{16, 144}, I_LIFE},
    {{16, 160}, I_LIFE},
    {{208, 48}, I_LIFE},
    {{208, 64}, I_LIFE},
    {{208, 144}, I_LIFE},
    {{208, 160}, I_LIFE},
    {{32, 48}, I_LIFE},
    {{192, 48}, I_LIFE},
    {{32, 160}, I_LIFE},
    {{192, 160}, I_LIFE}
};

void set_boss(game_assets_t *win, sfVector2f reset)
{
    wall_t *tmp = read_file(ROOM(boss), &win->entities.player->pos);

    if (tmp == NULL)
        return;
    free_wall(win->entities.wall);
    win->entities.wall = tmp;
    win->entities.player->angle = 0.0;
    win->shadow_room = false;
    if (reset.x != RESET || reset.y != RESET)
        win->entities.player->pos = reset;
    read_file_enemy(ENEMY(boss), win);
    add_all_weapon(win);
    add_item_array(win, item_array, sizeof(item_array) / sizeof(add_item_t));
    win->room = RM_BOSS;
    write_a_save(win, win->nb_save);
}
