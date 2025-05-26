/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** count_enemy.c
*/

#include "enemy.h"
#include "map.h"
#include "window_manage.h"

size_t count_enemy(game_assets_t *win)
{
    wall_t *wall = win->entities.wall;
    size_t count = 0;

    for (; wall != NULL; wall = wall->next)
        count += wall->object == IS_ENEMY;
    return count;
}
