/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** distance_to_wall.c
*/

#include <math.h>
#include "map.h"

float distance_to_wall(sfVector2f player_pos, wall_t *wall)
{
    sfVector2f ap = {player_pos.x - wall->pos1.x, player_pos.y - wall->pos1.y};
    sfVector2f ab = {wall->pos2.x - wall->pos1.x, wall->pos2.y - wall->pos1.y};
    float ab_squared = ab.x * ab.x + ab.y * ab.y;
    float dot = ap.x * ab.x + ap.y * ab.y;
    float t = fmax(0, fmin(1, dot / ab_squared));
    sfVector2f closest = {wall->pos1.x + ab.x * t, wall->pos1.y + ab.y * t};
    float dx = player_pos.x - closest.x;
    float dy = player_pos.y - closest.y;

    return sqrtf(dx * dx + dy * dy);
}
