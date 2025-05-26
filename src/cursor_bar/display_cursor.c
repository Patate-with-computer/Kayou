/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** display_cursor.c
*/

#include "cursor_bar.h"
#include "window_manage.h"

static void set_vertext(sfVertex vertex[4], game_assets_t *win,
    sfVector2f pos)
{
    sfVector2f p = pos;
    float wdt = WIDTH_CURSOR * win->scale.x;
    float hgt = HEIGHT_CURSOR * win->scale.y;

    p.y -= hgt / 2.f;
    vertex[0] = (sfVertex){.position = {p.x, p.y}, .color = color_bar};
    vertex[1] = (sfVertex){.position = {p.x, p.y + hgt}, .color = color_bar};
    vertex[2] = (sfVertex){.position = {p.x + wdt, p.y + hgt},
        .color = color_bar};
    vertex[3] = (sfVertex){.position = {p.x + wdt, p.y}, .color = color_bar};
}

static void draw(game_assets_t *win)
{
    sfVertexArray_setPrimitiveType(win->csfml.quad, sfQuads);
    sfRenderWindow_drawVertexArray(win->csfml.win, win->csfml.quad, NULL);
}

static void display_circle(game_assets_t *win, float pos_x, sfVector2f p)
{
    sfVector2f pos = {p.x + pos_x * win->scale.x, p.y};

    sfCircleShape_setFillColor(win->csfml.cursor_circle, color_bar);
    sfCircleShape_setRadius(win->csfml.cursor_circle, SIZE_CIRCLE_CURSOR);
    sfCircleShape_setOrigin(win->csfml.cursor_circle,
        (sfVector2f){SIZE_CIRCLE_CURSOR, SIZE_CIRCLE_CURSOR});
    sfCircleShape_setPosition(win->csfml.cursor_circle, pos);
    sfCircleShape_setScale(win->csfml.cursor_circle, win->scale);
    sfRenderWindow_drawCircleShape(win->csfml.win, win->csfml.cursor_circle,
        NULL);
}

#include <stdio.h>
static void display_text(game_assets_t *win, cursor_bar_t *cursor)
{
    sfVector2f pos = cursor->pos;
    char buff[BUFSIZ] = {0};
    float size_y = 0;

    sprintf(buff, "%.0f %%", cursor->percent);
    sfText_setString(win->csfml.text, buff);
    sfText_setColor(win->csfml.text, color_bar);
    sfText_setScale(win->csfml.text, win->scale);
    sfText_setCharacterSize(win->csfml.text, SIZE_TXT_CURSOR);
    size_y = sfText_getGlobalBounds(win->csfml.text).height;
    pos.x += (WIDTH_CURSOR + TEXT_ADD) * win->scale.x;
    pos.y -= size_y + (SIZE_CIRCLE_CURSOR / 2.0) * win->scale.y;
    sfText_setPosition(win->csfml.text, pos);
    sfRenderWindow_drawText(win->csfml.win, win->csfml.text, NULL);
}

void display_cursor(game_assets_t *win, size_t nb)
{
    cursor_bar_t *cursor = win->entities.cursor[nb];
    sfVertex vertex[4] = {0};

    cursor->percent = cursor->circle_pos * 100.f / WIDTH_CURSOR;
    if (cursor->percent <= 2.0)
        cursor->percent = 0.0;
    if (cursor->percent >= 98.0)
        cursor->percent = 100.0;
    move_circle(win, nb);
    sfVertexArray_clear(win->csfml.quad);
    set_vertext(vertex, win, cursor->pos);
    for (size_t i = 0; i < 4; ++i)
        sfVertexArray_append(win->csfml.quad, vertex[i]);
    display_circle(win, cursor->circle_pos, cursor->pos);
    draw(win);
    display_text(win, cursor);
}
