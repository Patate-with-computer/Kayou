/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** draw_txt.c
*/

#include <stdio.h>
#include <string.h>
#include "song_manage.h"
#include "player.h"
#include "window/window_manage.h"
#include "screen_text.h"
#include "lib.h"
#include "event_manage.h"

static void play_print_song(game_assets_t *win, size_t index, const char *str)
{
    static size_t max = 5;

    if (index % max == 0 && index < strlen(str)) {
        play_song(win, SG_BUTTON, win->entities.player->pos);
        max = randint(5) + 1;
    }
}

void draw_txt(game_assets_t *win, const char *txt, size_t mode)
{
    static bool prev_launch = false;
    char *buffer = NULL;
    size_t size_buffer = 0;

    if (txt != NULL) {
        buffer = get_buffer(txt, &prev_launch, win);
        size_buffer = strlen(buffer);
        play_print_song(win, size_buffer, txt);
        draw_all_lines(win, buffer, mode);
    }
    if (get_a_key(win, QUIT)) {
        if (txt == NULL || txt[size_buffer] == '\0') {
            win->put.txt = NULL;
            win->is_paused = false;
            win->is_text = false;
            win->is_echap_menu = false;
            prev_launch = false;
        }
    }
}
