/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** add_breakable_array.c
*/

#include <stddef.h>
#include "window_manage.h"
#include "map.h"

void add_breakable_array(game_assets_t *win,
    break_array_t const *array, size_t nb_array)
{
    for (size_t i = 0; i < nb_array; ++i) {
        create_breakable_wall(win, array[i].start, array[i].end,
            array[i].nb_text);
    }
}
