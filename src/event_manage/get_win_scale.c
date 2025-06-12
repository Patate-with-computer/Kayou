/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** get_win_scale.c
*/

#include "window/window_manage.h"

void get_win_scale(game_assets_t *win)
{
    sfVector2u size = sfRenderWindow_getSize(win->csfml.win);

    win->size = (sfVector2f){(float)size.x, (float)size.y};
    win->scale = (sfVector2f){(float)WIN_WIDTH / (float)win->size.x,
        (float)WIN_HEIGTH / (float)win->size.y};
}
