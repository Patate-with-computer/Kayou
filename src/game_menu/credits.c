/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** credits.c
*/

#include <math.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <string.h>
#include "window/window_manage.h"
#include "buttons.h"
#include "event_manage.h"
#include "texture_pack.h"
#include "lib.h"

void credit_menu(game_assets_t *window)
{
    sfTexture *texture = pack((set_texture_t){WALL_TYPE, W_CREDITS},
        window->text_pack);
    sfVector2u size = sfTexture_getSize(texture);
    float scale = window->size.y / (float)size.y;
    sfRenderStates st = {sfBlendAlpha, sfTransform_Identity, NULL, NULL};
    sfVector2f pos = {0};

    if (window->win_type != CREDITS_MENU)
        return;
    sfSprite_setScale(window->csfml.back, (sfVector2f){scale, scale});
    sfSprite_setTexture(window->csfml.back, texture, false);
    sfTransform_scale(&st.transform, window->scale.x, window->scale.y);
    pos.x -= (sfSprite_getGlobalBounds(window->csfml.back).width / 2.0) -
        window->size.x / 2.0;
    sfSprite_setPosition(window->csfml.back, pos);
    sfRenderWindow_drawSprite(window->csfml.win,
        window->csfml.back, &st);
    if ((int)fmod(get_millis(window->csfml.clock) / 1000, 2))
        blink_text(window, CREDITS_TXT, sfWhite, 50);
}
