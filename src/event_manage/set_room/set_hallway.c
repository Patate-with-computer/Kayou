/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** set_hallway.c
*/

#include "player.h"
#include "map.h"
#include "file_manage.h"
#include "ground_evt.h"
#include "enemy.h"
#include "save_manage.h"
#include "texture_pack.h"

static const break_array_t breakbable[] = {
    {{64, 0}, {96, 0}, W_WALL_1},
    {{160, -132}, {160, -100}, W_WOOD}
};

void set_hallway(game_assets_t *win, sfVector2f reset)
{
    wall_t *tmp = read_file(ROOM(hallway), &win->entities.player->pos);

    if (tmp == NULL)
        return;
    win->shadow_room = true;
    free_wall(win->entities.wall);
    win->entities.wall = tmp;
    if (reset.x != RESET || reset.y != RESET)
        win->entities.player->pos = reset;
    add_all_weapon(win);
    win->room = RM_HALLWAY;
    write_a_save(win, win->nb_save);
}

void set_hallway1(game_assets_t *win, sfVector2f reset)
{
    wall_t *tmp = read_file(ROOM(hallway1), &win->entities.player->pos);

    if (tmp == NULL)
        return;
    win->shadow_room = true;
    free_wall(win->entities.wall);
    win->entities.wall = tmp;
    if (reset.x != RESET || reset.y != RESET)
        win->entities.player->pos = reset;
    add_all_weapon(win);
    read_file_enemy(ENEMY(hallway1), win);
    add_breakable_array(win, breakbable,
        sizeof(breakbable) / sizeof(break_array_t));
    win->room = RM_HALLWAY_1;
    write_a_save(win, win->nb_save);
}

void set_hallway2(game_assets_t *win, sfVector2f reset)
{
    wall_t *tmp = read_file(ROOM(hallway2), &win->entities.player->pos);

    if (tmp == NULL)
        return;
    win->shadow_room = true;
    free_wall(win->entities.wall);
    win->entities.wall = tmp;
    if (reset.x != RESET || reset.y != RESET)
        win->entities.player->pos = reset;
    add_all_weapon(win);
    win->room = RM_HALLWAY_2;
    write_a_save(win, win->nb_save);
}
