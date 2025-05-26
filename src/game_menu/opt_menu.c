/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** opt_menu.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <string.h>
#include "window_manage.h"
#include "buttons.h"
#include "cursor_bar.h"
#include "event_manage.h"
#include "player.h"
#include "song_manage.h"
#include "texture_pack.h"
#include "target.h"
#include "save_manage.h"

static void load_text(game_assets_t *win, char const *text)
{
    free_texture_pack(win->text_pack);
    win->text_pack = init_texture_pack(text);
    free_target(win->entities.target);
    win->entities.target = init_target(TARGET_TYPE, T_TARGET, win->text_pack);
    destroy_menu_struct(win->menu);
    win->menu = init_window_data(win->text_pack);
    lunch_a_save(win, win->nb_save);
}

static void check_opt_button(game_assets_t *win)
{
    buttons_t *back = win->menu->buttons[BACK_BTN];
    buttons_t *sounds = win->menu->buttons[SOUNDS_BTN];
    buttons_t *music = win->menu->buttons[MUSIC_BUTTON];
    buttons_t *def = win->menu->buttons[DEFAULT_BTN];
    buttons_t *epitech = win->menu->buttons[EPITECH_BTN];

    if (check_button_hover(win, back) && get_one_click())
        win->win_type = win->previous_win;
    if (check_button_hover(win, sounds) && get_one_click())
        win->entities.cursor[SOUNDS_CURSOR]->circle_pos = 0;
    if (check_button_hover(win, music) && get_one_click())
        win->entities.cursor[MUSIC_CURSOR]->circle_pos = 0;
    if (check_button_hover(win, def) && get_one_click())
        return load_text(win, default_pack);
    if (check_button_hover(win, epitech) && get_one_click())
        return load_text(win, epitech_pack);
    set_volume(win);
}

void opt_menu(game_assets_t *win)
{
    win->restart_clock = true;
    display_background(win);
    print_button(win, BACK_BTN);
    print_button(win, MUSIC_BUTTON);
    print_button(win, SOUNDS_BTN);
    print_button(win, DEFAULT_BTN);
    print_button(win, EPITECH_BTN);
    display_cursor(win, SOUNDS_CURSOR);
    display_cursor(win, MUSIC_CURSOR);
    check_opt_button(win);
}
