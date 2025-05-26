/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** get_one_click.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <string.h>
#include "event_manage.h"

sfBool get_one_click(void)
{
    static sfBool prev_state = sfFalse;
    sfBool mouse_click = get_confirm_key();

    if (mouse_click && !prev_state) {
        prev_state = sfTrue;
        return sfTrue;
    }
    if (!mouse_click && prev_state)
        prev_state = sfFalse;
    return sfFalse;
}
