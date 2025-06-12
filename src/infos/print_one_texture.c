/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** print_one_text.c
*/

#include <string.h>
#include "player.h"
#include "texture_pack.h"
#include "window/window_manage.h"

static void set_vertext(sfVertex vertex[4], sfFloatRect rect, float size)
{
    vertex[0] = (sfVertex){
        .position = {rect.left, rect.top},
        .color = sfWhite,
        .texCoords = {0, 0}};
    vertex[1] = (sfVertex){
        .position = {rect.left, rect.top + rect.height},
        .color = sfWhite,
        .texCoords = {0, size}};
    vertex[2] = (sfVertex){
        .position = {rect.left + rect.width, rect.top + rect.height},
        .color = sfWhite,
        .texCoords = {size, size}};
    vertex[3] = (sfVertex){
        .position = {rect.left + rect.width, rect.top},
        .color = sfWhite,
        .texCoords = {size, 0}};
}

static void draw(game_assets_t *win, sfVertex vertex[4], sfTexture *text)
{
    sfRenderStates st = {sfBlendAlpha, sfTransform_Identity,
        text, NULL};

    sfVertexArray_clear(win->csfml.quad);
    for (size_t i = 0; i < 4; ++i)
        sfVertexArray_append(win->csfml.quad, vertex[i]);
    sfVertexArray_setPrimitiveType(win->csfml.quad, sfQuads);
    sfTransform_scale(&st.transform, win->scale.x, win->scale.y);
    sfRenderWindow_drawVertexArray(win->csfml.win, win->csfml.quad, &st);
}

static float print_background_texture(sfVector2f pos, game_assets_t *win,
    sfTexture *text)
{
    sfVertex vertex[4] = {0};
    sfFloatRect bounds = {pos.x, pos.y, SIZE_TEXT_WP, SIZE_TEXT_WP};
    sfTexture *texture = pack((set_texture_t){WALL_TYPE, W_TEXT_SPRITE},
        win->text_pack);

    bounds.top -= TO_ADD_ATH;
    bounds.left -= TO_ADD_ATH;
    bounds.height += SIZE_PRINT_ATH;
    bounds.width += SIZE_PRINT_ATH;
    set_vertext(vertex, bounds, (float)sfTexture_getSize(texture).x);
    draw(win, vertex, texture);
    bounds.top += TO_ADD_TEXTATH;
    bounds.left += TO_ADD_TEXTATH;
    bounds.height -= TO_ADD_TEXTATH * 2.0;
    bounds.width -= TO_ADD_TEXTATH * 2.0;
    set_vertext(vertex, bounds, SIZE_TEXT_WP);
    draw(win, vertex, text);
    return bounds.left + bounds.width;
}

float print_one_texture(sfTexture *text, sfVector2f pos, game_assets_t *win)
{
    float pos_x = 0;

    pos_x = print_background_texture(pos, win, text);
    return pos_x / win->scale.x;
}
