/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** get_a_key.c
*/

#include <stdio.h>
#include "window/window_manage.h"
#include "lib.h"
#include "screen_text.h"
#include "event_manage.h"

bool get_a_key(game_assets_t *win, size_t nb_key)
{
    static bool prev_key[3] = {0};
    bool actual_key = sfKeyboard_isKeyPressed(sfKeyA) ^
        get_joy_button(0, BUTTON_CIRCLE);
    bool state = false;

    if (actual_key && !prev_key[0] && (win->put.current + 1) % 3 == nb_key) {
        win->put.current = nb_key;
        prev_key[0] = true;
        state = true;
    }
    if (prev_key[0] && !actual_key)
        prev_key[0] = false;
    return state;
}
