/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** free_cursor.c
*/

#include "cursor_bar.h"
#include "lib.h"

cursor_bar_t **free_cursors(cursor_bar_t **cursor)
{
    if (cursor == NULL)
        return NULL;
    for (size_t i = 0; cursor_array[i].percent != END_CURSOR; ++i)
        MY_FREE(cursor[i]);
    MY_FREE(cursor);
    return NULL;
}
