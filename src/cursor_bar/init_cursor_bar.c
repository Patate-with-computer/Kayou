/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** init_cursor_bar.c
*/

#include <stdlib.h>
#include <string.h>
#include "cursor_bar.h"

size_t get_nb_cursor(void)
{
    size_t i = 0;

    for (; cursor_array[i].percent != END_CURSOR; ++i);
    return i;
}

static void set_null_array(cursor_bar_t **cursor)
{
    size_t i = 0;

    if (cursor == NULL)
        return;
    for (; cursor_array[i].percent != END_CURSOR; ++i)
        cursor[i] = NULL;
    cursor[i] = NULL;
}

static void set_percent(cursor_bar_t *cursor)
{
    cursor->percent = cursor->circle_pos * 100.f / WIDTH_CURSOR;
    if (cursor->percent <= 2.0)
        cursor->percent = 0.0;
    if (cursor->percent >= 98.0)
        cursor->percent = 100.0;
}

cursor_bar_t **init_cursors(void)
{
    cursor_bar_t **cursor = malloc(sizeof(cursor_bar_t *) *
        (get_nb_cursor() + 1));

    if (cursor == NULL)
        return NULL;
    set_null_array(cursor);
    for (size_t i = 0; cursor_array[i].percent != END_CURSOR; ++i) {
        cursor[i] = malloc(sizeof(cursor_bar_t));
        if (cursor[i] == NULL)
            return free_cursors(cursor);
        memcpy(cursor[i], &cursor_array[i], sizeof(cursor_bar_t));
        set_percent(cursor[i]);
    }
    return cursor;
}
