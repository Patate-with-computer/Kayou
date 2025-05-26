/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** launcher.c
*/

#include <stdlib.h>
#include <string.h>
#include "window_manage.h"
#include "buttons.h"
#include "event_manage.h"
#include "song_manage.h"

void launcher(game_assets_t *win)
{
    sfMusic_stop(win->song_lib->music);
    display_background(win);
    print_button(win, PLAY_BNT);
    print_button(win, OPTION_BNT);
    print_button(win, CREDIT_BTN);
    print_button(win, QUIT_BTN);
    win->previous_win = MAIN_MENU;
}

void check_launcher_hover(game_assets_t *window)
{
    if (window->win_type == MAIN_MENU) {
        if (check_button_hover(window, window->menu->buttons[0])
            && get_one_click())
            window->win_type = SAVE_MENU;
        if (check_button_hover(window, window->menu->buttons[6])
            && get_one_click())
            window->win_type = OPTIONS_MENU;
        if (check_button_hover(window, window->menu->buttons[12])
            && get_one_click())
            window->win_type = CREDITS_MENU;
        if (check_button_hover(window, window->menu->buttons[13])
            && get_one_click())
            window->win_type = EXIT_MENU;
    }
}
