/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** game_over.c
*/

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "window/window_manage.h"
#include "buttons.h"
#include "cursor_bar.h"
#include "event_manage.h"
#include "player.h"
#include "song_manage.h"
#include "lib.h"
#include "save_manage.h"

static void set_you_win_btn(game_assets_t *win)
{
    if (!sfJoystick_isConnected(0))
        return;
    while (win->horizontal_btn < 0)
        win->horizontal_btn = 2 + win->horizontal_btn;
    win->horizontal_btn %= 2;
    win->menu->buttons[RESTART_BTN]->hovered = win->horizontal_btn == 0;
    win->menu->buttons[MENU_RESTART_BNT]->hovered = win->horizontal_btn == 1;
}

static char *get_you_win_txt(game_assets_t *win)
{
    static char txt[BUFSIZ] = {0};

    memset(txt, 0, BUFSIZ);
    sprintf(txt, "You Win !!\nYour time: %s", get_timer_str(win));
    return txt;
}

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
    set_you_win_btn(win);
    sfRenderWindow_setMouseCursorVisible(win->csfml.win, sfTrue);
    if (check_button_hover(win, menu) && get_one_click())
        win->win_type = MAIN_MENU;
    if (check_button_hover(win, restart) && get_one_click()) {
        lunch_a_save(win, win->nb_save);
        win->win_type = MAZE;
    }
    if ((int)fmodf(get_millis(win->csfml.clock) / 1000, 2))
        blink_text(win, get_you_win_txt(win), sfGreen, 100);
}
