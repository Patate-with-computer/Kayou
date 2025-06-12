/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** null_game_assets_struct.c
*/

#include <stddef.h>
#include "window/window_manage.h"

static void null_csfml(game_assets_t *win)
{
    win->csfml.win = NULL;
    win->csfml.clock = NULL;
    win->csfml.clock_timer = NULL;
    win->csfml.shadow = NULL;
    win->csfml.quad = NULL;
    win->csfml.font = NULL;
    win->csfml.text = NULL;
    win->csfml.circle = NULL;
    win->csfml.cursor_circle = NULL;
    win->csfml.wp_shader = NULL;
    win->csfml.hover = NULL;
    win->csfml.sprite = NULL;
    win->csfml.back = NULL;
    win->csfml.rend_text = NULL;
    win->csfml.brume_shader = NULL;
}

void null_game_assets_struct(void *window)
{
    game_assets_t *win = (game_assets_t *)window;

    null_csfml(win);
    win->timer = 0.0f;
    win->entities.player = NULL;
    win->entities.cursor = NULL;
    win->entities.wall = NULL;
    win->entities.target = NULL;
    win->entities.echap_menu = NULL;
    win->song_lib = NULL;
    win->text_pack = NULL;
    win->menu = NULL;
}
