/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** get_max.c
*/

#include <math.h>
#include "window_manage.h"
#include "player.h"
#include "map.h"
#include "lib.h"

float get_max(game_assets_t *win, wall_t *weapon)
{
    sfVector2f dir = {cosf(win->entities.player->angle),
        sinf(win->entities.player->angle)};
    wall_t *curr = win->entities.wall;
    float dist = weapon->weapon->init_max_dist;
    float max = weapon->weapon->init_max_dist;
    sfVector2f origin = win->entities.player->pos;

    while (curr) {
        if (curr->object == IS_WALL)
            dist = update_closest_distance(origin, dir, curr, dist);
        if (dist < max) {
            win->entities.player->wall_to_break = curr;
            max = dist;
        }
        curr = curr->next;
    }
    return dist;
}
