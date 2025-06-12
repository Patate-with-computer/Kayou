/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** set_e_menu.c
*/

#include "window/window_manage.h"
#include "echap_menu.h"
#include "player.h"
#include "texture_pack.h"

static void print_background(game_assets_t *win)
{
    sfVertex vertex = {.position = {0, 0}, .color = echap_color};
    sfRenderStates st = {sfBlendAlpha, sfTransform_Identity, NULL, NULL};

    sfVertexArray_clear(win->csfml.quad);
    sfVertexArray_append(win->csfml.quad, vertex);
    vertex = (sfVertex){.position = {win->size.x, 0}, .color = echap_color};
    sfVertexArray_append(win->csfml.quad, vertex);
    vertex = (sfVertex){.position = {win->size.x, win->size.y},
        .color = echap_color};
    sfVertexArray_append(win->csfml.quad, vertex);
    vertex = (sfVertex){.position = {0, win->size.y}, .color = echap_color};
    sfVertexArray_append(win->csfml.quad, vertex);
    sfVertexArray_setPrimitiveType(win->csfml.quad, sfQuads);
    sfTransform_scale(&st.transform, win->scale.x, win->scale.y);
    sfRenderWindow_drawVertexArray(win->csfml.win, win->csfml.quad, &st);
}

#include <math.h>
#include "buttons.h"
static void set_price_btn(game_assets_t *win)
{
    if (!sfJoystick_isConnected(0))
        return;
    while (win->horizontal_btn < 0)
        win->horizontal_btn = NB_WEAPON + win->horizontal_btn;
    win->horizontal_btn %= NB_WEAPON;
}

void set_e_menu(game_assets_t *win)
{
    sfVector2f pos = {START_X_WP, START_Y_WP};

    if (!win->is_paused || win->is_text)
        return;
    print_background(win);
    if (win->is_echap_menu)
        return exit_menu(win);
    set_price_btn(win);
    for (size_t i = 0; i < NB_WEAPON; ++i) {
        if (pos.x >= win->size.x - SIZE_RECT_WP - START_X_WP) {
            pos.x = START_X_WP;
            pos.y += (SIZE_RECT_WP + BETWENN_WP);
        }
        display_one_weapon(win, pos, i);
        pos.x += (SIZE_RECT_WP + BETWENN_WP);
    }
}
