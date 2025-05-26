/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** is_in_rect.c
*/

#include <stdbool.h>
#include "window_manage.h"

bool is_in_rect(sfVector2f pos, sfFloatRect rect)
{
    bool a = (pos.x >= rect.left && pos.x <= rect.left + rect.width);
    bool b = (pos.y >= rect.top && pos.y <= rect.top + rect.height);

    return a && b;
}
