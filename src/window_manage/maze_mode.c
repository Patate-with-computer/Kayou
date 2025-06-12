/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** maze_mode.c
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
#include "screen_text.h"
#include "echap_menu.h"
#include "lib.h"

static void add_mana(game_assets_t *win)
{
    static float prev_time = 0.0;

    if (get_millis(win->csfml.clock) - prev_time >= 500.0) {
        if (!win->is_paused && win->entities.player->magic < 100)
            win->entities.player->magic += 1;
        prev_time = get_millis(win->csfml.clock);
    }
}

static void print_sprite(game_assets_t *win)
{
    target_t *target = win->entities.target;
    float pos_x = win->size.x / 2.0;
    float pos_y = (win->size.y - (float)POS(TARGET, TOADD) / win->scale.y);
    sfVector2f middle = {pos_x * win->scale.x, pos_y * win->scale.y};
    float scale = SCALE(target->size_x);
    sfVector2f sc = {scale * win->scale.x, scale * win->scale.y};

    sfSprite_setPosition(target->sprite, middle);
    sfSprite_setScale(target->sprite, sc);
    sfRenderWindow_drawSprite(win->csfml.win, target->sprite, NULL);
}

static void display_maze_mode(game_assets_t *win)
{
    display_horizon_bar(win);
    display_wall(win, win->entities.wall);
    display_rendertexture(win);
    print_sprite(win);
    display_minimap(win);
    set_e_menu(win);
    print_ath(win);
}

void maze_mode(game_assets_t *win)
{
    set_player_song(win->entities.player);
    set_volume(win);
    add_mana(win);
    if (!check_weapon_exist(win->entities.player))
        lunch_a_save(win, win->nb_save);
    check_demo_room(win);
    draw_background(win);
    set_all_distance(win, win->entities.player, win->entities.wall);
    sort_wall(&win->entities.wall);
    move_all_attack(win);
    display_maze_mode(win);
    display_screen_text(win, win->put.mode, win->put.txt);
    set_room_by_ground_evt(win);
    win->previous_win = MAZE;
}
