/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** window_loop.c
*/

#include <stdio.h>
#include <stdbool.h>
#include "window/window_manage.h"
#include "ground_evt.h"
#include "event_manage.h"
#include "file_manage.h"
#include "player.h"
#include "map.h"
#include "enemy.h"
#include "target.h"
#include "buttons.h"
#include "save_manage.h"
#include "song_manage.h"

static void set_maze(game_assets_t *win)
{
    if (win->win_type != MAZE)
        return;
    maze_mode(win);
    if (win->entities.player->life <= 0)
        win->win_type = GAME_OVER;
    if (win->room == RM_BOSS && count_enemy(win) == 0)
        win->win_type = YOU_WIN;
}

static void set_other_type(game_assets_t *win)
{
    if (win->win_type == SAVE_MENU)
        save_menu(win);
    if (win->win_type == CREDITS_MENU)
        credit_menu(win);
    if (win->win_type == OPTIONS_MENU)
        opt_menu(win);
}

#include "lib.h"
static void set_timer_values(game_assets_t *win)
{
    if (win->win_type == MAZE && !win->is_paused)
        win->timer += get_millis(win->csfml.clock_timer);
    sfClock_restart(win->csfml.clock_timer);
}

#include "cursor_bar.h"
void window_loop(game_assets_t *win)
{
    sfRenderWindow_clear(win->csfml.win, sfBlack);
    sfRenderTexture_clear(win->csfml.rend_text, sfBlack);
    if (win->win_type == MAIN_MENU)
        launcher(win);
    set_timer_values(win);
    set_vertical_btn(win);
    set_horizontal_btn(win);
    set_maze(win);
    game_over(win);
    you_win(win);
    set_other_type(win);
    event_manage(win);
    check_launcher_hover(win);
    check_save_menu_hover(win);
    sfRenderWindow_display(win->csfml.win);
}
