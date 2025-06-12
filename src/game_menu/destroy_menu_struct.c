/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** destroy_menu_struct.c
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "window/window_manage.h"
#include "buttons.h"
#include "lib.h"

void destroy_menu_struct(actual_window_t *menu)
{
    if (menu == NULL)
        return;
    if (menu->win_back != NULL)
        sfTexture_destroy(menu->win_back->b);
    if (menu->buttons != NULL) {
        for (size_t i = 0; menu->buttons[i] != NULL; i++) {
            sfSprite_destroy(menu->buttons[i]->sprite);
            MY_FREE(menu->buttons[i]);
        }
        MY_FREE(menu->buttons);
    }
    if (menu->win_back != NULL) {
        sfSprite_destroy(menu->win_back->s);
        MY_FREE(menu->win_back);
    }
    MY_FREE(menu);
}
