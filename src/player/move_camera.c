/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** move_camera.c
*/

#include <math.h>
#include <stdbool.h>
#include "window_manage.h"
#include "event_manage.h"
#include "player.h"
#include "map.h"
#include "lib.h"

float get_mov_joy(size_t joy_nb, sfJoystickAxis axis)
{
    float mov = sfJoystick_getAxisPosition(joy_nb, axis);

    if (fabsf(mov) <= 10.0)
        mov = 0.0;
    return mov / 20.0;
}

static void joystick_move(game_assets_t *win)
{
    float speed = win->entities.player->speed;
    float cam_x_joy = 0.0;
    float mov_left_right_joy = 0.0;
    float mov_top_bottom_joy = 0.0;

    if (sfJoystick_isConnected(0)) {
        cam_x_joy = get_mov_joy(0, sfJoystickU);
        win->entities.player->angle += cam_x_joy * CAM_SENS;
        mov_left_right_joy = SPEED(
                (get_mov_joy(0, sfJoystickY) * MOVE_SENS) * speed,
                get_millis(win->csfml.clock), win->entities.player->anc_time);
        if (mov_left_right_joy != 0.0)
            move_to_a_pos(win, Y_AXCIS, true, mov_left_right_joy);
        mov_top_bottom_joy = SPEED(
                (get_mov_joy(0, sfJoystickX) * MOVE_SENS) * speed,
                get_millis(win->csfml.clock), win->entities.player->anc_time);
        if (mov_top_bottom_joy != 0.0)
            move_to_a_pos(win, X_AXCIS, false, mov_top_bottom_joy);
    }
}

static float normalize_angle(float angle)
{
    while (angle > M_PI)
        angle -= 2 * M_PI;
    while (angle < -1 * M_PI)
        angle += 2 * M_PI;
    return angle;
}

void change_camera_angle(game_assets_t *win)
{
    sfVector2i win_center = {(int)win->size.x / 2, (int)win->size.y / 2};
    float m_pos = (float)sfMouse_getPositionRenderWindow(win->csfml.win).x;
    float dx = m_pos - win_center.x;

    if (!win->is_paused) {
        joystick_move(win);
        win->entities.player->angle += dx * CAM_SENS;
        win->entities.player->angle =
            normalize_angle(win->entities.player->angle);
        sfMouse_setPositionRenderWindow(win_center, win->csfml.win);
    }
    sfRenderWindow_setMouseCursorVisible(win->csfml.win, win->is_paused);
}
