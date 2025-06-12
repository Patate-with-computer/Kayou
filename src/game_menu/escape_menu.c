/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** escape_menu.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <string.h>
#include "window/window_manage.h"
#include "buttons.h"
#include "event_manage.h"

static void set_escape_menu_btn(game_assets_t *win)
{
    if (!sfJoystick_isConnected(0))
        return;
    while (win->vertical_btn < 0)
        win->vertical_btn = 4 + win->vertical_btn;
    win->vertical_btn %= 4;
    win->menu->buttons[CONTINUE_BTN]->hovered = win->vertical_btn == 0;
    win->menu->buttons[OPTION_BNT]->hovered = win->vertical_btn == 1;
    win->menu->buttons[MENU_BTN]->hovered = win->vertical_btn == 2;
    win->menu->buttons[QUIT_BTN]->hovered = win->vertical_btn == 3;
}

void exit_menu(game_assets_t *win)
{
    check_exit_menu_hover(win);
    print_button(win, CONTINUE_BTN);
    print_button(win, OPTION_BNT);
    print_button(win, MENU_BTN);
    print_button(win, QUIT_BTN);
    set_escape_menu_btn(win);
}

void check_exit_menu_hover(game_assets_t *window)
{
    if (check_button_hover(window, window->menu->buttons[CONTINUE_BTN])
        && get_one_click()) {
        if (window->is_echap_menu && window->is_paused) {
            window->is_echap_menu = false;
            window->is_paused = false;
            return;
        }
    }
    if (check_button_hover(window, window->menu->buttons[OPTION_BNT])
        && get_one_click())
        window->win_type = OPTIONS_MENU;
    if (check_button_hover(window, window->menu->buttons[MENU_BTN])
        && get_one_click()) {
        window->win_type = MAIN_MENU;
        window->previous_win = MAZE;
    }
    if (check_button_hover(window, window->menu->buttons[QUIT_BTN])
        && get_one_click())
        window->win_type = EXIT_MENU;
}
