/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** display_background.c
*/


#include "window/window_manage.h"
#include "buttons.h"
#include "event_manage.h"

void display_background(game_assets_t *win)
{
    sfRenderStates st = {sfBlendAlpha, sfTransform_Identity, NULL, NULL};
    float scale = win->size.y / 500.f;

    sfSprite_setScale(win->menu->win_back->s, (sfVector2f){scale, scale});
    sfTransform_scale(&st.transform, win->scale.x, win->scale.y);
    sfRenderWindow_drawSprite(win->csfml.win,
        win->menu->win_back->s, &st);
}
