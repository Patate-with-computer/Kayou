/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** demo.c
*/

#include "file_manage.h"
#include "enemy.h"
#include "window/window_manage.h"
#include "screen_text.h"
#include "ground_evt.h"
#include "items.h"
#include "texture_pack.h"

static const add_item_t item_array[] = {
    {{224, 128}, I_BARIL}};

static void set_demo_file(game_assets_t *win)
{
    win->put.mode = LITLE_MODE;
    if (win->actual_demo == TENTACULE) {
        read_file_enemy(ENEMY(room_demo2), win);
        win->put.current = TALK;
        win->put.txt = (char *)end_first_phase;
    }
    if (win->actual_demo == MOB_AND_ENEMY) {
        read_file_enemy(ENEMY(room_demo3), win);
        win->put.current = TALK;
        win->put.txt = (char *)end_second_phase;
    }
    if (win->actual_demo == ALL_ENEMIES) {
        read_file_enemy(ENEMY(room_demo4), win);
        add_item_array(win, item_array, 1);
        win->put.current = TALK;
        win->put.txt = (char *)end_last_phase;
        win->is_brume = true;
    }
}

void check_demo_room(game_assets_t *win)
{
    move_cheat(win);
    if (win->room != RM_DEMO)
        return;
    if (count_enemy(win) == 0) {
        win->actual_demo += 1;
        set_demo_file(win);
        if (win->actual_demo > ALL_ENEMIES)
            win->win_type = YOU_WIN;
    }
}
