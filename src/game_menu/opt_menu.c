/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** opt_menu.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <string.h>
#include "window/window_manage.h"
#include "buttons.h"
#include "cursor_bar.h"
#include "event_manage.h"
#include "player.h"
#include "song_manage.h"
#include "texture_pack.h"
#include "target.h"
#include "save_manage.h"


static void set_opt_btn(game_assets_t *win)
{
    if (!sfJoystick_isConnected(0))
        return;
    while (win->vertical_btn < 0)
        win->vertical_btn = 4 + win->vertical_btn;
    while (win->horizontal_btn < 0)
        win->horizontal_btn = 2 + (win->vertical_btn == 3) +
            win->horizontal_btn;
    win->horizontal_btn %= 2 + (win->vertical_btn == 1);
    win->vertical_btn %= 4;
    win->menu->buttons[BACK_BTN]->hovered = win->vertical_btn == 0;
    win->menu->buttons[MUSIC_BUTTON]->hovered = win->vertical_btn == 1;
    win->menu->buttons[SOUNDS_BTN]->hovered = win->vertical_btn == 2;
    win->menu->buttons[EPITECH_BTN]->hovered = win->vertical_btn == 3 &&
        win->horizontal_btn == 0;
    win->menu->buttons[DEFAULT_BTN]->hovered = win->vertical_btn == 3 &&
        win->horizontal_btn == 1;
    if (win->vertical_btn == 1)
        move_circle_joystick(win, MUSIC_CURSOR);
    if (win->vertical_btn == 2)
        move_circle_joystick(win, SOUNDS_CURSOR);
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
        return load_text(win, "special_epitech");
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
    set_opt_btn(win);
    check_opt_button(win);
}
