/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** move_player.c
*/

#include <math.h>
#include <stdbool.h>
#include "window_manage.h"
#include "event_manage.h"
#include "player.h"
#include "map.h"
#include "lib.h"

float get_distance(sfVector2f pt1, sfVector2f pt2)
{
    sfVector2f dp = {pt2.x - pt1.x, pt2.y - pt1.y};

    return sqrt(dp.x * dp.x + dp.y * dp.y);
}

static void slide_player(game_assets_t *win, sfVector2f add, wall_t *wall)
{
    sfVector2f vec_wall = {wall->pos2.x - wall->pos1.x,
        wall->pos2.y - wall->pos1.y};
    sfVector2f vec_add = {add.x - win->entities.player->pos.x,
        add.y - win->entities.player->pos.y};
    float dot_ab = vec_add.x * vec_wall.x + vec_add.y * vec_wall.y;
    float dot_bb = vec_wall.x * vec_wall.x + vec_wall.y * vec_wall.y;
    sfVector2f slide = {vec_wall.x * (dot_ab / dot_bb),
        vec_wall.y * (dot_ab / dot_bb)};
    sfVector2f vec_player = {win->entities.player->pos.x + slide.x,
        win->entities.player->pos.y + slide.y};

    for (; wall != NULL && wall->distance <= MAX_DISTANCE_CHECK;
        wall = wall->next) {
        if (wall->object != IS_WALL)
            continue;
        if (distance_to_wall(vec_player, wall) <= MAX_DISTANCE_WALL)
            return;
    }
    win->entities.player->pos = vec_player;
}

static bool check_walls(wall_t *wall, sfVector2f add, game_assets_t *win)
{
    for (; wall != NULL && wall->distance <= MAX_DISTANCE_CHECK;
        wall = wall->next) {
        if (wall->object != IS_WALL)
            continue;
        if (distance_to_wall(add, wall) <= MAX_DISTANCE_WALL)
            return false;
    }
    win->entities.player->pos = add;
    return true;
}

void move_to_a_pos(game_assets_t *win, float to_add,
    bool neg, float speed)
{
    sfVector2f add = {cosf(to_add + win->entities.player->angle) * speed,
        sinf(to_add + win->entities.player->angle) * speed};
    wall_t *wall = win->entities.wall;

    if (neg == true) {
        add.x *= -1;
        add.y *= -1;
    }
    add.x += win->entities.player->pos.x;
    add.y += win->entities.player->pos.y;
    for (; wall != NULL && wall->object != IS_WALL; wall = wall->next);
    if (wall == NULL) {
        win->entities.player->pos = add;
        return;
    }
    if (check_walls(wall, add, win) == false)
        slide_player(win, add, wall);
}

void move_player(game_assets_t *win)
{
    float speed = SPEED(win->entities.player->speed,
            get_millis(win->csfml.clock), win->entities.player->anc_time);

    if (win->restart_clock) {
        speed = 0;
        win->restart_clock = false;
    }
    change_camera_angle(win);
    if (!win->is_paused) {
        if (sfKeyboard_isKeyPressed(sfKeyZ))
            move_to_a_pos(win, Y_AXCIS, false, speed);
        if (sfKeyboard_isKeyPressed(sfKeyS))
            move_to_a_pos(win, Y_AXCIS, true, speed);
        if (sfKeyboard_isKeyPressed(sfKeyD))
            move_to_a_pos(win, X_AXCIS, false, speed);
        if (sfKeyboard_isKeyPressed(sfKeyQ))
            move_to_a_pos(win, X_AXCIS, true, speed);
    }
    win->entities.player->anc_time = get_millis(win->csfml.clock);
}
