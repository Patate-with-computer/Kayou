/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** move_camera.c
*/

#include <math.h>
#include <stdbool.h>
#include "window/window_manage.h"
#include "event_manage.h"
#include "player.h"
#include "map.h"
#include "lib.h"

float get_mov_joy(size_t joy_nb, sfJoystickAxis axis)
{
    float mov = sfJoystick_getAxisPosition(joy_nb, axis);

    if (fabsf(mov) <= 10.0)
        mov = 0.0;
    return mov / 100.0;
}

static void joystick_move(game_assets_t *win)
{
    float speed = SPEED(win->entities.player->speed,
        get_millis(win->csfml.clock), win->entities.player->anc_time);
    float mov_left_right_joy = speed * get_mov_joy(0, sfJoystickY);
    float mov_top_bottom_joy = speed * get_mov_joy(0, sfJoystickX);

    if (speed >= 5.0)
        return;
    mov_left_right_joy = speed * get_mov_joy(0, sfJoystickY);
    if (mov_left_right_joy != 0.0)
        move_to_a_pos(win, Y_AXCIS, true, mov_left_right_joy);
    if (mov_top_bottom_joy != 0.0)
        move_to_a_pos(win, X_AXCIS, false, mov_top_bottom_joy);
}

static void change_joystick_camera(game_assets_t *win, float speed_cam)
{
    float move_cam = 0.0f;

    joystick_move(win);
    move_cam = get_mov_joy(0, sfJoystickU);
    win->entities.player->angle +=
        move_cam * fabsf(move_cam * 0.8f) * speed_cam;
}

void change_camera_angle(game_assets_t *win)
{
    sfVector2i win_center = {(int)win->size.x / 2, (int)win->size.y / 2};
    float m_pos = (float)sfMouse_getPositionRenderWindow(win->csfml.win).x;
    float dx = m_pos - win_center.x;
    float speed_cam = SPEED(JOY_SENS, get_millis(win->csfml.clock),
        win->entities.player->anc_time);

    if (!win->is_paused) {
        set_lock_wall(win);
        if (sfJoystick_isConnected(0))
            change_joystick_camera(win, speed_cam);
        else
            win->entities.player->angle += dx * CAM_SENS;
        sfMouse_setPositionRenderWindow(win_center, win->csfml.win);
    }
    win->entities.player->anc_time = get_millis(win->csfml.clock);
    sfRenderWindow_setMouseCursorVisible(win->csfml.win, win->is_paused);
}
