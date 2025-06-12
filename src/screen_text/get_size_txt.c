/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** get_size_txt.c
*/

#include "window/window_manage.h"
#include "screen_text.h"

sfVector2f get_size_txt(game_assets_t *win, const char *str)
{
    sfFloatRect size = {0};
    sfText *txt = win->csfml.text;

    sfText_setCharacterSize(txt, TEXT_SIZE);
    sfText_setScale(txt, win->scale);
    sfText_setColor(txt, text_color);
    sfText_setString(txt, str);
    size = sfText_getGlobalBounds(txt);
    return (sfVector2f){size.width, size.height};
}
