/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** set_all_null_menu.c
*/

#include "buttons.h"

void set_all_null_menu(void *to_null)
{
    actual_window_t *win = (actual_window_t *)to_null;

    win->buttons = NULL;
    win->win_back = NULL;
}
