/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** display_price.c
*/

#include <stdio.h>
#include <string.h>
#include "player.h"
#include "ground_evt.h"
#include "window_manage.h"
#include "map.h"

static void print_text(game_assets_t *win, float price, sfVector2f pos)
{
    sfVector2f txt_pos = pos;
    char str[BUFSIZ] = {0};
    sfFloatRect rect = {0};

    sprintf(str, "%.0f$", price);
    sfText_setString(win->csfml.text, str);
    sfText_setCharacterSize(win->csfml.text, SIZE_TEXT_PRICE);
    rect = sfText_getGlobalBounds(win->csfml.text);
    txt_pos.x *= win->scale.x;
    txt_pos.x += (SIZE_RECT_WP / 2.0) * win->scale.x - rect.width / 2.0;
    txt_pos.y *= win->scale.y;
    txt_pos.y += (SIZE_RECT_WP / 3.0) * win->scale.y - rect.height / 3.0;
    sfText_setColor(win->csfml.text, price_color);
    sfText_setPosition(win->csfml.text, txt_pos);
    sfText_setScale(win->csfml.text, win->scale);
    sfRenderWindow_drawText(win->csfml.win, win->csfml.text, NULL);
}

void display_price(game_assets_t *win, sfVector2f pos, size_t nb_weapon)
{
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(win->csfml.win);
    sfVector2f m_pos_f = {(float)m_pos.x, (float)m_pos.y};
    sfFloatRect rect = {pos.x, pos.y, SIZE_RECT_WP, SIZE_RECT_WP};
    weapon_t *weapon = win->entities.player->weapon[nb_weapon]->weapon;
    player_t *pl = win->entities.player;

    if (!is_in_rect(m_pos_f, rect) || pl->get_weapon[nb_weapon])
        return;
    print_text(win, weapon->price, pos);
}
