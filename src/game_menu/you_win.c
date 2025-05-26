/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** game_over.c
*/

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "window_manage.h"
#include "buttons.h"
#include "cursor_bar.h"
#include "event_manage.h"
#include "player.h"
#include "song_manage.h"
#include "lib.h"
#include "save_manage.h"

void you_win(game_assets_t *win)
{
    buttons_t *menu = win->menu->buttons[MENU_RESTART_BNT];
    buttons_t *restart = win->menu->buttons[RESTART_BTN];

    if (win->win_type != YOU_WIN)
        return;
    win->restart_clock = true;
    display_background(win);
    print_button(win, RESTART_BTN);
    print_button(win, MENU_RESTART_BNT);
    sfRenderWindow_setMouseCursorVisible(win->csfml.win, sfTrue);
    if (check_button_hover(win, menu) && get_one_click())
        win->win_type = MAIN_MENU;
    if (check_button_hover(win, restart) && get_one_click()) {
        lunch_a_save(win, win->nb_save);
        win->win_type = MAZE;
    }
    if ((int)fmod(get_millis(win->csfml.clock) / 1000, 2))
        blink_text(win, "You Win !!", sfGreen, 250);
}
