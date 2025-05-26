/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** blink_text.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <string.h>
#include "window_manage.h"
#include "buttons.h"
#include "event_manage.h"

void blink_text(game_assets_t *window, char *text, sfColor color, size_t size)
{
    sfRenderStates st = {sfBlendAlpha, sfTransform_Identity, NULL, NULL};
    sfVector2f position = {0};

    sfTransform_scale(&st.transform, window->scale.x, window->scale.y);
    sfText_setString(window->csfml.text, text);
    sfText_setCharacterSize(window->csfml.text, size);
    sfText_setColor(window->csfml.text, color);
    position.x -= (sfText_getGlobalBounds(window->csfml.text).width / 2.0) -
        window->size.x / 2.0;
    sfText_setPosition(window->csfml.text, position);
    sfRenderWindow_drawText(window->csfml.win, window->csfml.text, &st);
}
