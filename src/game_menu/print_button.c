/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** print_button.c
*/

#include "buttons.h"
#include "window/window_manage.h"

void print_button(game_assets_t *win, size_t nb_btn)
{
    buttons_t *button = win->menu->buttons[nb_btn];
    sfRenderStates st = {sfBlendAlpha, sfTransform_Identity, NULL, NULL};
    sfVector2f pos = {button->button_pos.x / win->scale.x,
        button->button_pos.y / win->scale.y};
    sfFloatRect rect = sfSprite_getGlobalBounds(button->sprite);

    sfTransform_scale(&st.transform, win->scale.x, win->scale.y);
    sfSprite_setPosition(button->sprite, pos);
    sfSprite_setOrigin(button->sprite,
        (sfVector2f){rect.width / 2.0, rect.height / 2.0});
    if (check_button_hover(win, button))
        st.shader = win->csfml.hover;
    sfRenderWindow_drawSprite(win->csfml.win, button->sprite, &st);
}
