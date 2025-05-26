/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** init_a_wall.c
*/

#include <stdlib.h>
#include "file_manage.h"
#include "map.h"
#include "player.h"
#include "type.h"
#include "texture_pack.h"

wall_t *init_a_wall(sfVector2f new_pos[3])
{
    wall_t *wall = malloc(sizeof(wall_t));

    if (wall == NULL)
        return NULL;
    wall->pos1 = new_pos[0];
    wall->pos2 = new_pos[1];
    wall->printbale = NOT_PRINTABLE;
    wall->rect = new_pos[2];
    wall->next = NULL;
    wall->texture = (set_texture_t){WALL_TYPE, W_WALL_1};
    wall->object = IS_WALL;
    wall->enemy = NULL;
    wall->weapon = NULL;
    wall->item = NULL;
    wall->enemy_attack = NULL;
    wall->distance = 0.0;
    wall->is_breakable = false;
    wall->hidden = false;
    return wall;
}
