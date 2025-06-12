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

static void set_text_info(game_assets_t *win, const char *str, sfVector2f pos)
{
    sfText_setCharacterSize(win->csfml.text, SIZE_TEXT_ATH);
    sfText_setOrigin(win->csfml.text, (sfVector2f){0, 0});
    sfText_setString(win->csfml.text, str);
    sfText_setPosition(win->csfml.text, pos);
    sfText_setScale(win->csfml.text, win->scale);
    sfText_setColor(win->csfml.text, ath_text_color);
}

char *get_timer_str(game_assets_t *win)
{
    static char time_str[BUFSIZ] = {0};
    size_t minute = (size_t)win->timer / (1000.0f * 60);
    size_t m_in_s = minute * 1000 * 60;
    size_t seconde = (size_t)((win->timer - (float)(m_in_s)) / 1000.0f);
    size_t s_in_s = seconde * 1000;
    size_t millis = (size_t)(win->timer - (float)(s_in_s + m_in_s)) / 10;

    memset(time_str, 0, BUFSIZ);
    sprintf(time_str, "%.2lu:%.2lu.%.2lu", minute, seconde, millis);
    return time_str;
}

float print_one_text(float info, const char *s, sfVector2f pos,
    game_assets_t *win)
{
    char str[BUFSIZ] = {0};
    float pos_x = 0;

    memset(str, 0, sizeof(str));
    if (strcmp(s, "Life") == 0 && win->is_god_mode)
        sprintf(str, "Life\nGOD MODE");
    else if (strcmp(s, "Timer") == 0) {
        sprintf(str, "Timer\n%s", get_timer_str(win));
    } else
        sprintf(str, "%s\n%3.0f", s, info);
    pos.x *= win->scale.x;
    pos.y *= win->scale.y;
    set_text_info(win, str, pos);
    pos_x = print_background_text(win, win->csfml.text);
    sfRenderWindow_drawText(win->csfml.win, win->csfml.text, NULL);
    return pos_x / win->scale.x;
}
