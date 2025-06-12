/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** get_buffer.c
*/

#include <string.h>
#include <stdio.h>
#include "window/window_manage.h"
#include "lib.h"
#include "screen_text.h"

static size_t get_index(game_assets_t *win, const char *txt, size_t ind)
{
    size_t index = ind;

    if (index < strlen(txt))
        ++index;
    else
        win->put.current = ADVANCE;
    return index;
}

char *get_buffer(const char *txt, bool *prev_launch, game_assets_t *win)
{
    static char buffer[BUFSIZ] = {0};
    static float anc_time = 0;
    static size_t index = 0;

    if (!*prev_launch) {
        *prev_launch = true;
        index = 0;
        anc_time = get_millis(win->csfml.clock);
    }
    if (get_millis(win->csfml.clock) - anc_time >= TIME_TXT) {
        index = get_index(win, txt, index);
        anc_time = get_millis(win->csfml.clock);
        if (get_a_key(win, ADVANCE))
            index = strlen(txt);
    }
    memset(buffer, 0, BUFSIZ);
    strncpy(buffer, txt, index);
    return buffer;
}
