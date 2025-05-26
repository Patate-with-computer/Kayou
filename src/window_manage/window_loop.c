/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** window_loop.c
*/

#include <stdio.h>
#include <stdbool.h>
#include "window_manage.h"
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

void maze_mode(game_assets_t *win)
{
    set_player_song(win->entities.player);
    set_volume(win);
    add_mana(win);
    if (!check_weapon_exist(win->entities.player))
        lunch_a_save(win, win->nb_save);
    draw_background(win);
    set_all_distance(win, win->entities.player, win->entities.wall);
    sort_wall(&win->entities.wall);
    move_all_attack(win);
    display_wall(win, win->entities.wall);
    display_rendertexture(win);
    print_sprite(win);
    display_minimap(win);
    set_e_menu(win);
    print_ath(win);
    set_room_by_ground_evt(win);
    win->previous_win = MAZE;
}

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

#include "cursor_bar.h"
void window_loop(game_assets_t *win)
{
    sfRenderWindow_clear(win->csfml.win, sfBlack);
    sfRenderTexture_clear(win->csfml.rend_text, sfBlack);
    if (win->win_type == MAIN_MENU)
        launcher(win);
    set_maze(win);
    game_over(win);
    you_win(win);
    if (win->win_type == SAVE_MENU)
        save_menu(win);
    if (win->win_type == CREDITS_MENU)
        credit_menu(win);
    if (win->win_type == OPTIONS_MENU)
        opt_menu(win);
    event_manage(win);
    check_launcher_hover(win);
    check_save_menu_hover(win);
    sfRenderWindow_display(win->csfml.win);
}
