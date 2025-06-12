/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** launcher.c
*/

#include <stdlib.h>
#include <string.h>
#include "window/window_manage.h"
#include "buttons.h"
#include "event_manage.h"
#include "song_manage.h"

static void set_luncher_btn(game_assets_t *win)
{
    if (!sfJoystick_isConnected(0))
        return;
    while (win->vertical_btn < 0)
        win->vertical_btn = 4 + win->vertical_btn;
    win->vertical_btn %= 4;
    win->menu->buttons[PLAY_BNT]->hovered = win->vertical_btn == 0;
    win->menu->buttons[OPTION_BNT]->hovered = win->vertical_btn == 1;
    win->menu->buttons[CREDIT_BTN]->hovered = win->vertical_btn == 2;
    win->menu->buttons[QUIT_BTN]->hovered = win->vertical_btn == 3;
}

void launcher(game_assets_t *win)
{
    sfMusic_stop(win->song_lib->music);
    display_background(win);
    print_button(win, PLAY_BNT);
    print_button(win, OPTION_BNT);
    print_button(win, CREDIT_BTN);
    print_button(win, QUIT_BTN);
    set_luncher_btn(win);
    win->previous_win = MAIN_MENU;
}

void check_launcher_hover(game_assets_t *window)
{
    if (window->win_type == MAIN_MENU) {
        if (check_button_hover(window, window->menu->buttons[PLAY_BNT])
            && get_one_click())
            window->win_type = SAVE_MENU;
        if (check_button_hover(window, window->menu->buttons[OPTION_BNT])
            && get_one_click())
            window->win_type = OPTIONS_MENU;
        if (check_button_hover(window, window->menu->buttons[CREDIT_BTN])
            && get_one_click())
            window->win_type = CREDITS_MENU;
        if (check_button_hover(window, window->menu->buttons[QUIT_BTN])
            && get_one_click())
            window->win_type = EXIT_MENU;
    }
}
