/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** display_wall.c
*/

#include <math.h>
#include <stdlib.h>
#include "window/window_manage.h"
#include "map.h"
#include "enemy.h"
#include "player.h"
#include "items.h"
#include "ground_evt.h"

static int check_brume(float dist, float brume[MAX_BRUME])
{
    for (size_t i = 0; i < MAX_BRUME; ++i) {
        if (!(brume[i] >= dist && brume[i] <= dist + CHECK_DIST_BRUME))
            continue;
        return i;
    }
    return -1;
}

static bool display_brume(game_assets_t *win, wall_t *wall,
    float brume[MAX_BRUME])
{
    int count = 0;
    void (*display_function[])(game_assets_t *, wall_t *) = {
        display_quad, display_enemy, display_weapon, display_item,
        display_attack};

    if (!win->is_brume || wall->object != IS_WALL)
        return false;
    count = check_brume(wall->distance, brume);
    if (count != -1) {
        display_one_bar(win, brume[count]);
        brume[count] = -1;
    }
    if (wall->distance < MAX_REND_BRUME)
        display_function[wall->object](win, wall);
    return true;
}

static void recursive(game_assets_t *win, wall_t *wall, float brume[MAX_BRUME])
{
    void (*display_function[])(game_assets_t *, wall_t *) = {
        display_quad, display_enemy, display_weapon, display_item,
        display_attack};

    if (wall == NULL)
        return;
    recursive(win, wall->next, brume);
    if (!display_brume(win, wall, brume) && wall->distance < MAX_DIST_RENDER)
        display_function[wall->object](win, wall);
    if (wall->object == IS_ENEMY)
        move_an_enemy(win, wall);
}

void display_wall(game_assets_t *win, wall_t *wall)
{
    float to_print[MAX_BRUME] = {0};
    float step = (MAX_REND_BRUME - DIST_BRUME) / MAX_BRUME;
    size_t start = 0;

    for (size_t i = 0; i < MAX_BRUME; ++i)
        to_print[i] = DIST_BRUME + (float)i * step;
    recursive(win, wall, to_print);
    if (!win->is_brume)
        return;
    for (; to_print[start] == -1 && start < MAX_BRUME; ++start);
    for (size_t i = start; i < MAX_BRUME; ++i) {
        if (to_print[i] == -1)
            break;
        display_one_bar(win, to_print[i]);
    }
}
