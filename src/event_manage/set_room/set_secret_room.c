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

void set_secret(game_assets_t *win, sfVector2f reset)
{
    wall_t *tmp = read_file(ROOM(secret_room), &win->entities.player->pos);

    if (tmp == NULL)
        return;
    free_wall(win->entities.wall);
    win->entities.wall = tmp;
    win->is_brume = false;
    win->shadow_room = false;
    if (reset.x != RESET || reset.y != RESET)
        win->entities.player->pos = reset;
    read_file_enemy(ENEMY(secret_room), win);
    add_all_weapon(win);
    win->room = RM_SECRET;
    write_a_save(win, win->nb_save);
}
