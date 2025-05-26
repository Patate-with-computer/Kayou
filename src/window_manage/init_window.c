/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** init_window.c
*/

#include <stdlib.h>
#include "window_manage.h"
#include "player.h"
#include "map.h"
#include "file_manage.h"
#include "enemy.h"
#include "target.h"
#include "buttons.h"
#include "items.h"
#include "song_manage.h"
#include "texture_pack.h"
#include "lib.h"
#include "echap_menu.h"
#include "cursor_bar.h"
#include "ground_evt.h"

static bool init_text(game_assets_t *win)
{
    win->shadow_room = false;
    win->csfml.cursor_circle = sfCircleShape_create();
    win->csfml.font = sfFont_createFromFile(FONT_STR);
    win->csfml.text = sfText_create();
    win->restart_clock = true;
    if (win->csfml.font == NULL || win->csfml.text == NULL ||
            win->csfml.circle == NULL)
        return false;
    sfText_setFont(win->csfml.text, win->csfml.font);
    sfText_setColor(win->csfml.text, font_color);
    return true;
}

static game_assets_t *init_entities(game_assets_t *win)
{
    win->entities.player = init_player();
    win->entities.target = init_target(TARGET_TYPE, T_TARGET, win->text_pack);
    win->entities.wall = NULL;
    win->is_paused = false;
    win->entities.echap_menu = init_echap_menu();
    win->csfml.sprite = sfSprite_create();
    win->csfml.back = sfSprite_create();
    win->csfml.rend_text = sfRenderTexture_create(WIN_WIDTH, WIN_HEIGTH,
        false);
    win->csfml.light_shader = sfShader_createFromFile(NULL, NULL, brum_frag);
    win->entities.cursor = init_cursors();
    if (win->entities.player == NULL || win->entities.target == NULL ||
        win->entities.echap_menu == NULL || win->csfml.sprite == NULL ||
        win->csfml.rend_text == NULL || win->entities.cursor == NULL ||
        win->csfml.back == NULL)
        return free_window(win);
    return win;
}

static game_assets_t *init_csfml(game_assets_t *win)
{
    sfVideoMode mode = {WIN_WIDTH, WIN_HEIGTH, BPP};
    sfWindowStyle win_mode = sfClose | sfResize;

    win->csfml.win = sfRenderWindow_create(mode, "Wolf3d", win_mode, NULL);
    if (win->csfml.win == NULL)
        return free_window(win);
    sfRenderWindow_setFramerateLimit(win->csfml.win, MAX_FPS);
    sfRenderWindow_setActive(win->csfml.win, sfTrue);
    win->csfml.clock = sfClock_create();
    win->csfml.shadow = sfShader_createFromFile(NULL, NULL, shadow_frag);
    win->csfml.hover = sfShader_createFromFile(NULL, NULL, hover_frag);
    win->csfml.wp_shader = sfShader_createFromFile(NULL, NULL, wp_frag);
    win->csfml.quad = sfVertexArray_create();
    win->csfml.circle = sfCircleShape_create();
    if (win->csfml.quad == NULL || win->csfml.shadow == NULL ||
            win->csfml.clock == NULL || win->csfml.hover == NULL ||
            init_text(win) == false || win->csfml.circle == NULL)
        return free_window(win);
    win->previous_win = MAIN_MENU;
    return init_entities(win);
}

game_assets_t *init_window(void)
{
    game_assets_t *win = malloc(sizeof(game_assets_t));

    if (win == NULL)
        return free_window(win);
    set_all_null(win, WIN_LIB_TYPE);
    win->text_pack = init_texture_pack(default_pack);
    win->scale = (sfVector2f){1.0, 1.0};
    win->size = (sfVector2f){WIN_WIDTH, WIN_HEIGTH};
    win->fov = FOV;
    win->win_type = 0;
    win->room = RM_INTRO;
    win->song_lib = init_lib();
    win->nb_save = 0;
    win->is_echap_menu = false;
    if (win->text_pack == NULL)
        return free_window(win);
    win->menu = init_window_data(win->text_pack);
    if (win->menu == NULL || win->song_lib == NULL)
        return free_window(win);
    return init_csfml(win);
}
