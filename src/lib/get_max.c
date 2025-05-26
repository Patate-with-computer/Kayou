/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** get_max.c
*/

#include <math.h>
#include "player.h"
#include "map.h"
#include <SFML/Graphics.h>

float get_ray_segment_distance(sfVector2f origin, sfVector2f dir,
    sfVector2f p1, sfVector2f p2)
{
    float dx2 = p2.x - p1.x;
    float dy2 = p2.y - p1.y;
    float denom = dir.x * dy2 - dir.y * dx2;
    float t = 0;
    float u = 0;
    float num_t = (p1.x - origin.x) * dy2 - (p1.y - origin.y) * dx2;
    float num_u = (p1.x - origin.x) * dir.y - (p1.y - origin.y) * dir.x;

    if (denom == 0)
        return -1;
    t = num_t / denom;
    u = num_u / denom;
    if (t >= 0 && u >= 0 && u <= 1)
        return t;
    return -1;
}

float update_closest_distance(sfVector2f origin, sfVector2f dir,
    wall_t *wall, float max_dist)
{
    float dist = max_dist;
    float t = get_ray_segment_distance(origin, dir, wall->pos1, wall->pos2);

    if (t < 0)
        return dist;
    if (t < dist)
        dist = t;
    return dist;
}

float raycast_to_walls(wall_t *walls, sfVector2f origin, float angle,
    float max_dist)
{
    sfVector2f dir = {cosf(angle), sinf(angle)};
    wall_t *curr = walls;
    float dist = max_dist;

    while (curr) {
        if (curr->object == IS_WALL)
            dist = update_closest_distance(origin, dir, curr, dist);
        curr = curr->next;
    }
    return dist;
}
