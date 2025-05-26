/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** play_menu.c
*/

#include "window_manage.h"
#include "buttons.h"
#include "event_manage.h"
#include "save_manage.h"
#include "map.h"

static void print_save_menu(game_assets_t *win)
{
    display_background(win);
    print_button(win, BACK_BTN);
}

void save_menu(game_assets_t *win)
{
    print_save_menu(win);
    display_save(win);
}

void check_save_menu_hover(game_assets_t *window)
{
    if (window->win_type == SAVE_MENU) {
        if (check_button_hover(window, window->menu->buttons[BACK_BTN])
            && get_one_click()) {
            window->win_type = MAIN_MENU;
            }
    }
}
