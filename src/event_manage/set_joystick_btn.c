/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** set_joystick_btn.c
*/

#include "window/window_manage.h"
#include "event_manage.h"

void set_horizontal_btn(game_assets_t *win)
{
    static bool prev_st = false;
    bool actual = get_mov_joy(0, sfJoystickX) >= 0.5f;
    bool actual_less = get_mov_joy(0, sfJoystickX) <= -0.5f;

    if (!sfJoystick_isConnected(0)) {
        prev_st = false;
        return;
    }
    if (actual_less && !prev_st) {
        win->horizontal_btn = (win->horizontal_btn - 1);
        prev_st = true;
    }
    if (actual && !prev_st) {
        win->horizontal_btn = (win->horizontal_btn + 1);
        prev_st = true;
    }
    if (!(actual || actual_less) && prev_st)
        prev_st = false;
}

void set_vertical_btn(game_assets_t *win)
{
    static bool prev_st = false;
    bool actual = get_mov_joy(0, sfJoystickY) >= 0.5f;
    bool actual_less = get_mov_joy(0, sfJoystickY) <= -0.5f;

    if (!sfJoystick_isConnected(0)) {
        prev_st = false;
        return;
    }
    if (actual_less && !prev_st) {
        win->vertical_btn = (win->vertical_btn - 1);
        prev_st = true;
    }
    if (actual && !prev_st) {
        win->vertical_btn = (win->vertical_btn + 1);
        prev_st = true;
    }
    if (!(actual || actual_less) && prev_st)
        prev_st = false;
}
