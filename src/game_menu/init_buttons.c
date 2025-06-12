/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** init_buttons.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "window/window_manage.h"
#include "buttons.h"
#include "lib.h"
#include <stdarg.h>

static buttons_t *free_one_button(buttons_t *button)
{
    if (button == NULL)
        return NULL;
    if (button->sprite != NULL)
        sfSprite_destroy(button->sprite);
    MY_FREE(button);
    return NULL;
}

static void set_buttons(buttons_t **buttons)
{
    size_t i = 0;
    sfIntRect rect = {0};

    while (buttons[i] != NULL) {
        rect = (sfIntRect){buttons[i]->texture_pos.left * SIZE_X,
                            buttons[i]->texture_pos.top * SIZE_Y,
                            buttons[i]->texture_pos.width,
                            buttons[i]->texture_pos.height};
        sfSprite_setTextureRect(buttons[i]->sprite, rect);
        sfSprite_setPosition(buttons[i]->sprite, buttons[i]->button_pos);
        sfSprite_setScale(buttons[i]->sprite, (sfVector2f){1.0, 1.0});
        i++;
    }
}

static buttons_t **check_buttons(buttons_t **buttons)
{
    bool error = false;

    if (buttons == NULL)
        return NULL;
    for (unsigned int i = 0; i < NB_BUTTON - 1; i++) {
        if (buttons[i] == NULL) {
            error = true;
        }
    }
    if (error == true) {
        for (unsigned int i = 0; i < NB_BUTTON - 1; i++) {
            free_one_button(buttons[i]);
        }
        MY_FREE(buttons);
        return NULL;
    }
    set_buttons(buttons);
    return buttons;
}

static buttons_t *init_btn_data(buttons_t *btn, va_list params)
{
    sfIntRect texture_pos = {va_arg(params, int), va_arg(params, int),
        SIZE_X, SIZE_Y};
    sfVector2f button_pos = {va_arg(params, int), va_arg(params, int)};
    sfIntRect button_area = {button_pos.x, button_pos.y, SIZE_X, SIZE_Y};

    btn->sprite = sfSprite_create();
    if (btn->sprite == NULL)
        return free_one_button(btn);
    sfSprite_setTexture(btn->sprite, va_arg(params, sfTexture *), sfTrue);
    btn->texture_pos = texture_pos;
    btn->button_pos = button_pos;
    btn->button_area = button_area;
    btn->hovered = 0;
    return btn;
}

static buttons_t *init_one_btn(char *start, ...)
{
    va_list params = {0};
    buttons_t *btn = malloc(sizeof(buttons_t));

    va_start(params, start);
    if (btn == NULL)
        return NULL;
    btn = init_btn_data(btn, params);
    va_end(params);
    return btn;
}

buttons_t **init_buttons(sfTexture *texture)
{
    buttons_t **buttons = malloc(NB_BUTTON * sizeof(buttons_t *));
    button_info_t inf = {0};

    if (buttons == NULL)
        return NULL;
    for (size_t i = 0; button_array[i].pos_x_text != -1; ++i) {
        inf = button_array[i];
        buttons[i] = init_one_btn(NULL, inf.pos_x_text, inf.pos_y_text,
            inf.pos_x_win, inf.pos_y_win, texture);
    }
    buttons[NB_BUTTON - 1] = NULL;
    return check_buttons(buttons);
}
