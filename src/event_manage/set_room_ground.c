/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** set_room_ground.c
*/

#include "player.h"
#include "ground_evt.h"
#include "window_manage.h"

void set_room_by_ground_evt(game_assets_t *win)
{
    for (size_t i = 0; grd[i].func != NULL; ++i) {
        if (win->room != grd[i].room)
            continue;
        if (is_in_rect(win->entities.player->pos, grd[i].rect) == false)
            continue;
        grd[i].func(win, grd[i].reset);
        break;
    }
}
