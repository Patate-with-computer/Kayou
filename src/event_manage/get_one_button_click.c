/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** get_one_button_click.c
*/

#include <SFML/Graphics.h>
#include "event_manage.h"

sfBool get_one_e(void)
{
    static sfBool prev_state = sfFalse;
    sfBool key_pressed = sfKeyboard_isKeyPressed(sfKeyE) ^
        get_joy_button(0, BUTTON_CROIX);

    if (key_pressed && !prev_state) {
        prev_state = sfTrue;
        return sfTrue;
    }
    if (!key_pressed && prev_state)
        prev_state = sfFalse;
    return sfFalse;
}

sfBool get_one_escape(void)
{
    static sfBool prev_state = sfFalse;
    sfBool key_pressed = sfKeyboard_isKeyPressed(sfKeyEscape) ^
        get_joy_button(0, BUTTON_OPTION);

    if (key_pressed && !prev_state) {
        prev_state = sfTrue;
        return sfTrue;
    }
    if (!key_pressed && prev_state)
        prev_state = sfFalse;
    return sfFalse;
}

sfBool get_one_button_click(sfKeyCode key)
{
    static sfBool prev_state = sfFalse;
    sfBool key_pressed = sfKeyboard_isKeyPressed(key);

    if (key_pressed && !prev_state) {
        prev_state = sfTrue;
        return sfTrue;
    }
    if (!key_pressed && prev_state)
        prev_state = sfFalse;
    return sfFalse;
}
