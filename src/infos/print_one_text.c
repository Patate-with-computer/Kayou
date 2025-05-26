/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** print_one_text.c
*/

#include <string.h>
#include "player.h"
#include "texture_pack.h"
#include "window_manage.h"

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
    sfRenderWindow_drawVertexArray(win->csfml.win, win->csfml.quad, &st);
}

static float print_background_text(game_assets_t *win, sfText *text)
{
    sfVertex vertex[4] = {0};
    sfFloatRect bounds = sfText_getGlobalBounds(text);
    sfTexture *texture = pack((set_texture_t){WALL_TYPE, W_TEXT_SPRITE},
        win->text_pack);
    float size = (float)sfTexture_getSize(texture).x;

    bounds.top -= TO_ADD_ATH * win->scale.y;
    bounds.height += TO_ADD_ATH * 2.0 * win->scale.y;
    bounds.left -= TO_ADD_ATH * win->scale.x;
    bounds.width += TO_ADD_ATH * 2.0 * win->scale.x;
    set_vertext(vertex, bounds, size);
    draw(win, vertex, texture);
    return bounds.left + bounds.width;
}

float print_one_text(float info, const char *s, sfVector2f pos,
    game_assets_t *win)
{
    char str[BUFSIZ] = {0};
    float pos_x = 0;

    memset(str, 0, sizeof(str));
    sprintf(str, "%s\n%3.0f", s, info);
    pos.x *= win->scale.x;
    pos.y *= win->scale.y;
    sfText_setCharacterSize(win->csfml.text, SIZE_TEXT_ATH);
    sfText_setString(win->csfml.text, str);
    sfText_setPosition(win->csfml.text, pos);
    sfText_setScale(win->csfml.text, win->scale);
    sfText_setColor(win->csfml.text, ath_text_color);
    pos_x = print_background_text(win, win->csfml.text);
    sfRenderWindow_drawText(win->csfml.win, win->csfml.text, NULL);
    return pos_x / win->scale.x;
}
