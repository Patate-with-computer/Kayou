/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** move_circle.c
*/

#include <math.h>
#include "ground_evt.h"
#include "window/window_manage.h"
#include "cursor_bar.h"
#include "event_manage.h"

void move_circle(game_assets_t *win, size_t nb)
{
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(win->csfml.win);
    sfVector2f m_posf = {m_pos.x, m_pos.y};
    cursor_bar_t *cursor = win->entities.cursor[nb];
    sfVector2f pos = cursor->pos;
    sfFloatRect rect = {
        pos.x / win->scale.x, pos.y / win->scale.y - SIZE_CIRCLE_CURSOR,
        WIDTH_CURSOR, SIZE_CIRCLE_CURSOR * 2.0};

    if (is_in_rect(m_posf, rect) && sfMouse_isButtonPressed(sfMouseLeft))
        cursor->circle_pos = m_posf.x - cursor->pos.x / win->scale.x;
}

static bool is_in_rect_joy(sfVector2f pos, sfFloatRect rect)
{
    bool a = (pos.x >= rect.left && pos.x <= rect.left + rect.width);
    bool b = (pos.y >= rect.top && pos.y <= rect.top + rect.height);

    return a && b;
}

void move_circle_joystick(game_assets_t *win, size_t nb)
{
    cursor_bar_t *cursor = win->entities.cursor[nb];
    sfVector2f pos = cursor->pos;
    float joy = get_mov_joy(0, sfJoystickU);
    sfVector2f m_posf = {pos.x + joy + cursor->circle_pos, pos.y};
    sfFloatRect rect = {
        pos.x / win->scale.x, pos.y / win->scale.y - SIZE_CIRCLE_CURSOR,
        WIDTH_CURSOR, SIZE_CIRCLE_CURSOR * 2.0};

    if (is_in_rect_joy(m_posf, rect))
        cursor->circle_pos = m_posf.x - cursor->pos.x / win->scale.x;
}
