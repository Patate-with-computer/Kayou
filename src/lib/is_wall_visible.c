/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** is_wall_visible.c
*/

#include <math.h>
#include "lib.h"
#include "player.h"
#include "map.h"

sfVector2f get_center(wall_t *wall)
{
    sfVector2f center = {
        (wall->pos1.x + wall->pos2.x) * 0.5f,
        (wall->pos1.y + wall->pos2.y) * 0.5f
    };

    if (wall->object != IS_WALL)
        center = wall->pos1;
    return center;
}

static float angle_diff(float a, float b)
{
    float diff = a - b;

    while (diff < -1.0f * M_PI)
        diff += 2 * M_PI;
    while (diff > M_PI)
        diff -= 2 * M_PI;
    return diff;
}

float get_wall_visibility_angle(wall_t *wall, player_t *pl, wall_t *walls)
{
    sfVector2f center = get_center(wall);
    sfVector2f to_center = {center.x - pl->pos.x, center.y - pl->pos.y};
    float dist = hypotf(to_center.x, to_center.y);
    float angle = atan2f(to_center.y, to_center.x);
    float max_angle = MAX_ANGLE_LIGHT * M_PI / 180.0f;
    float diff = angle_diff(angle, pl->angle);

    if (raycast_to_walls(walls, pl->pos, angle, dist) < dist - 1.0f)
        return -1.0f;
    return fabsf(diff) / max_angle;
}
