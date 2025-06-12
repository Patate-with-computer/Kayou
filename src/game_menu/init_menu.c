/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** init_menu.c
*/

#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.h>
#include "window/window_manage.h"
#include "buttons.h"
#include "lib.h"
#include "texture_pack.h"

static menu_background_t *background(void)
{
    menu_background_t *background = malloc(sizeof(menu_background_t));

    if (background == NULL)
        return NULL;
    background->b = sfTexture_createFromFile(
        "assets/texture_pack/default/wall/background.png", NULL);
    background->s = sfSprite_create();
    return background;
}

actual_window_t *init_window_data(texture_pack_t *text_pack)
{
    actual_window_t *window_data = malloc(sizeof(actual_window_t));

    if (window_data == NULL)
        return NULL;
    set_all_null(window_data, MENU_LIB_TYPE);
    window_data->buttons_texture = (set_texture_t){WALL_TYPE, W_BUTTONS};
    window_data->win_back = background();
    if (window_data->win_back == NULL || window_data->win_back->b == NULL) {
        destroy_menu_struct(window_data);
        return NULL;
    }
    sfSprite_setTexture(window_data->win_back->s,
        window_data->win_back->b, sfTrue);
    window_data->buttons = init_buttons(
        pack(window_data->buttons_texture, text_pack));
    if (window_data->buttons == NULL) {
        destroy_menu_struct(window_data);
        return NULL;
    }
    return window_data;
}
