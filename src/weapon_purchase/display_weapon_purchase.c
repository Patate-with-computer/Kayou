/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** display_weapon_purchase.c
*/

#include "player.h"
#include "texture_pack.h"
#include "window/window_manage.h"
#include "map.h"
#include "ground_evt.h"
#include "event_manage.h"

static void set_vertex(sfVertex vertex[4], sfFloatRect rect)
{
    vertex[0] = (sfVertex){.position = {rect.left, rect.top},
        .color = sfWhite, .texCoords = {0, 0}};
    vertex[1] = (sfVertex){.position = {rect.left, rect.top + rect.height},
        .color = sfWhite, .texCoords = {0, SIZE_TEXT_WP}};
    vertex[2] = (sfVertex){.position = {
        rect.left + rect.width, rect.top + rect.height},
        .color = sfWhite, .texCoords = {SIZE_TEXT_WP, SIZE_TEXT_WP}};
    vertex[3] = (sfVertex){.position = {rect.left + rect.width, rect.top},
        .color = sfWhite, .texCoords = {SIZE_TEXT_WP, 0}};
}

static sfVector2f set_shader(game_assets_t *win, sfFloatRect rect,
    weapon_t *weapon, size_t nb_weapon)
{
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(win->csfml.win);
    sfVector2f m_pos_f = {(float)m_pos.x, (float)m_pos.y};
    player_t *pl = win->entities.player;
    sfShader *sh = win->csfml.wp_shader;

    if (sh == NULL)
        return m_pos_f;
    sfShader_setBoolUniform(sh, "is_in_rect",
        is_in_rect2(m_pos_f, rect) || (sfJoystick_isConnected(0) &&
        (int)nb_weapon == win->horizontal_btn));
    sfShader_setBoolUniform(sh, "enough", pl->money >= weapon->price);
    sfShader_setBoolUniform(sh, "already", pl->get_weapon[nb_weapon]);
    sfShader_setBoolUniform(sh, "is_actual", nb_weapon == pl->weapon_name);
    return m_pos_f;
}

static void draw(game_assets_t *win, weapon_t *wp,
    sfFloatRect rect, size_t nb_weapon)
{
    sfTexture *text = pack((set_texture_t){WEAPON_TYPE, wp->text_purchase},
        win->text_pack);
    sfRenderStates st = {sfBlendAlpha, sfTransform_Identity, text,
        win->csfml.wp_shader};
    sfVector2f m_pos = set_shader(win, rect, wp, nb_weapon);
    player_t *player = win->entities.player;

    if ((is_in_rect2(m_pos, rect) ||
        (sfJoystick_isConnected(0) &&
        win->horizontal_btn == (int)nb_weapon)) && get_one_click()) {
        if (player->money >= wp->price && !player->get_weapon[nb_weapon]) {
            player->get_weapon[nb_weapon] = true;
            player->money -= wp->price;
        }
        if (player->get_weapon[nb_weapon] && player->weapon_name != nb_weapon)
            player->weapon_name = nb_weapon;
    }
    sfVertexArray_setPrimitiveType(win->csfml.quad, sfQuads);
    sfTransform_scale(&st.transform, win->scale.x, win->scale.y);
    sfRenderWindow_drawVertexArray(win->csfml.win, win->csfml.quad, &st);
}

void display_one_weapon(game_assets_t *win, sfVector2f pos, size_t nb_weapon)
{
    sfVertex vertex[4] = {0};
    wall_t *weapon = win->entities.player->weapon[nb_weapon];
    sfFloatRect rect = {pos.x, pos.y, SIZE_RECT_WP, SIZE_RECT_WP};

    if (weapon == NULL)
        return;
    sfVertexArray_clear(win->csfml.quad);
    set_vertex(vertex, rect);
    for (size_t i = 0; i < 4; ++i)
        sfVertexArray_append(win->csfml.quad, vertex[i]);
    draw(win, weapon->weapon, rect, nb_weapon);
    display_price(win, pos, nb_weapon);
}
