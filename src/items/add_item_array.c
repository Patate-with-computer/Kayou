/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** add_item_array.c
*/

#include "window_manage.h"
#include "items.h"

void add_item_array(game_assets_t *win, add_item_t const *array, size_t nb)
{
    for (size_t i = 0; i < nb; ++i)
        add_specific_item(win, array[i].text_nb, array[i].pos);
}
