/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** put_the_txt.c
*/

#include <stdio.h>
#include <string.h>
#include "song_manage.h"
#include "player.h"
#include "window/window_manage.h"
#include "screen_text.h"
#include "lib.h"

void put_the_txt(game_assets_t *win, const char *txt,
    size_t mode, size_t nb_add)
{
    sfVector2f size = get_size_txt(win, txt);
    float top_size = MARGIN_TOP_BIG;
    float left = (win->size.x * win->scale.x - size.x) / 2.0f;

    if (mode == LITLE_MODE)
        top_size = GET_SIZE(win->size.y, win->scale.y);
    top_size += MARGIN_TOP_BIG + (MARGIN_TOP_BIG * MULT_FACT) * nb_add;
    sfText_setPosition(win->csfml.text, (sfVector2f){
        left, top_size * win->scale.y
    });
    sfRenderWindow_drawText(win->csfml.win, win->csfml.text, NULL);
}
