/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** is_hovered.c
*/

#include "buttons.h"
#include "window/window_manage.h"
#include "ground_evt.h"

bool check_button_hover(game_assets_t *window, buttons_t *button)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->csfml.win);
    sfFloatRect rect = sfSprite_getGlobalBounds(button->sprite);
    sfVector2f pos = {mouse.x, mouse.y};

    if (sfJoystick_isConnected(0) && button->hovered)
        return true;
    if (sfJoystick_isConnected(0) && !button->hovered)
        return false;
    return is_in_rect(pos, rect);
}
