/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** display_wall.c
*/

#include "window_manage.h"
#include "map.h"
#include "enemy.h"
#include "player.h"
#include "items.h"

void display_wall(game_assets_t *win, wall_t *wall)
{
    void (*display_function[])(game_assets_t *, wall_t *) = {
        display_quad, display_enemy, display_weapon, display_item,
        display_attack
    };

    if (wall == NULL)
        return;
    display_wall(win, wall->next);
    display_function[wall->object](win, wall);
}
