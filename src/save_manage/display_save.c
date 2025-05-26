/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** display_weapon.c
*/

#include "window_manage.h"
#include "map.h"
#include "buttons.h"
#include "texture_pack.h"
#include "save_manage.h"
#include "ground_evt.h"
#include "event_manage.h"

static void set_vertext(sfVertex vertex[4], float pos_x)
{
    vertex[0] = (sfVertex){.position = {pos_x, POS_Y_SAVE},
        .color = sfWhite, .texCoords = {0, 0}};
    vertex[1] = (sfVertex){.position = {pos_x, POS_Y_SAVE + SIZE_RECT_SAVE},
        .color = sfWhite, .texCoords = {0, SIZE_TEXT_SAVE}};
    vertex[2] = (sfVertex){.position = {
        pos_x + SIZE_RECT_SAVE, POS_Y_SAVE + SIZE_RECT_SAVE},
        .color = sfWhite, .texCoords = {SIZE_TEXT_SAVE, SIZE_TEXT_SAVE}};
    vertex[3] = (sfVertex){.position = {pos_x + SIZE_RECT_SAVE, POS_Y_SAVE},
        .color = sfWhite, .texCoords = {SIZE_TEXT_SAVE, 0}};
}

static void draw(game_assets_t *win, size_t n, float pos_x, int *is_click)
{
    sfRenderStates st = {sfBlendAlpha, sfTransform_Identity, NULL, NULL};
    sfFloatRect rect = {pos_x, POS_Y_SAVE, SIZE_RECT_SAVE, SIZE_RECT_SAVE};
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(win->csfml.win);
    sfVector2f m_pos_f = {(float)m_pos.x, (float)m_pos.y};

    if (is_in_rect(m_pos_f, rect) || *is_click == (int)n) {
        st.shader = win->csfml.hover;
        if (get_confirm_key()) {
            *is_click = n;
            win->nb_save = n;
        }
    }
    if (is_file_exist(get_filename(n))) {
        st.texture = pack(
            (set_texture_t){WALL_TYPE, W_SAVE_IMAGE}, win->text_pack);
    }
    sfTransform_scale(&st.transform, win->scale.x, win->scale.y);
    sfVertexArray_setPrimitiveType(win->csfml.quad, sfQuads);
    sfRenderWindow_drawVertexArray(win->csfml.win, win->csfml.quad, &st);
}

static void display_one_save(game_assets_t *win, size_t n, float pos_x,
    int *is_click)
{
    sfVertex vertex[4] = {0};

    sfVertexArray_clear(win->csfml.quad);
    set_vertext(vertex, pos_x);
    for (size_t i = 0; i < 4; ++i)
        sfVertexArray_append(win->csfml.quad, vertex[i]);
    draw(win, n, pos_x, is_click);
}

void check_save_button(game_assets_t *win, int is_click)
{
    buttons_t *lunch = win->menu->buttons[LUNCH_BTN];
    buttons_t *remove = win->menu->buttons[REMOVE_BTN];

    if (is_click == -1)
        return;
    print_button(win, LUNCH_BTN);
    print_button(win, REMOVE_BTN);
    if (check_button_hover(win, remove) && get_one_click())
        remove_a_save(win->nb_save);
    if (check_button_hover(win, lunch) && get_one_click()) {
        lunch_a_save(win, win->nb_save);
        win->win_type = MAZE;
        win->previous_win = MAZE;
    }
}

void display_save(game_assets_t *win)
{
    static int is_click = -1;
    float pos_x = 0;

    for (size_t i = 0; i < NBR_MAX_SAVE; ++i) {
        pos_x = (win->size.x / 2.0) +
            (win->size.x / (float)NBR_MAX_SAVE) * ((float)i - 1) -
            SIZE_RECT_SAVE / 2.0;
        display_one_save(win, i, pos_x, &is_click);
    }
    check_save_button(win, is_click);
}
