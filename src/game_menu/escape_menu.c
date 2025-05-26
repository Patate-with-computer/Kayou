/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** escape_menu.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <string.h>
#include "window_manage.h"
#include "buttons.h"
#include "event_manage.h"

void exit_menu(game_assets_t *win)
{
    check_exit_menu_hover(win);
    print_button(win, CONTINUE_BTN);
    print_button(win, OPTION_BNT);
    print_button(win, MENU_BTN);
    print_button(win, QUIT_BTN);
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
