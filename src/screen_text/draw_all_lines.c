/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** draw_all_lines.c
*/

#include <string.h>
#include "window/window_manage.h"
#include "screen_text.h"
#include "lib.h"

static size_t get_cut(game_assets_t *win, char *start)
{
    sfVector2f size = {0};
    size_t len = strlen(start);
    size_t cut = len;

    for (size_t j = 1; j <= len; ++j) {
        if (start[j] == '\n') {
            cut = j;
            break;
        }
        size = get_size_txt(win, get_cutstr(start, j));
        if (size.x > (win->size.x * win->scale.x - MARGIN_LEFT * 12.0f)) {
            cut = j - 1;
            break;
        }
    }
    return cut;
}

void draw_all_lines(game_assets_t *win, char *buffer, size_t mode)
{
    char *start = buffer;
    size_t line_num = 0;
    size_t max_lines = (win->size.y / (int)(MARGIN_TOP_BIG * MULT_FACT)) - 3;
    size_t cut = 0;

    if (mode == LITLE_MODE)
        max_lines = 3;
    while (*start != '\0' && line_num < max_lines) {
        cut = get_cut(win, start);
        if (cut == 0)
            break;
        put_the_txt(win, get_cutstr(start, cut), mode, line_num);
        start += cut;
        line_num++;
    }
}
