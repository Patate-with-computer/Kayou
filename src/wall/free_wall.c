/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** free_wall.c
*/

#include <stdlib.h>
#include "lib.h"
#include "player.h"
#include "map.h"
#include "enemy.h"

void free_one_wall(wall_t *wall)
{
    if (wall == NULL)
        return;
    MY_FREE(wall->enemy);
    MY_FREE(wall->weapon);
    MY_FREE(wall->item);
    MY_FREE(wall->enemy_attack);
    MY_FREE(wall);
}

void free_wall(wall_t *wall)
{
    if (wall == NULL)
        return;
    free_wall(wall->next);
    free_one_wall(wall);
    return;
}
