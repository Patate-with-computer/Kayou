/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** play_menu.c
*/

#include "window/window_manage.h"
#include "buttons.h"
#include "event_manage.h"
#include "save_manage.h"
#include "map.h"

static void set_save_btn(game_assets_t *win)
{
    if (!sfJoystick_isConnected(0))
        return;
    while (win->vertical_btn < 0)
        win->vertical_btn = 3 + win->vertical_btn;
    while (win->horizontal_btn < 0)
        win->horizontal_btn = 2 + (win->vertical_btn == 1) +
            win->horizontal_btn;
    win->horizontal_btn %= 2 + (win->vertical_btn == 1);
    win->vertical_btn %= 3;
    win->menu->buttons[BACK_BTN]->hovered = win->vertical_btn == 0;
    win->menu->buttons[LUNCH_BTN]->hovered = win->vertical_btn == 2 &&
            win->horizontal_btn == 0;
    win->menu->buttons[REMOVE_BTN]->hovered = win->vertical_btn == 2 &&
            win->horizontal_btn == 1;
}

static void print_save_menu(game_assets_t *win)
{
    display_background(win);
    print_button(win, BACK_BTN);
    set_save_btn(win);
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
