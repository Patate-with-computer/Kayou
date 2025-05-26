/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** init_echap_menu.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "echap_menu.h"
#include "lib.h"

echap_menu_t *free_echap_menu(echap_menu_t *echap_menu)
{
    if (echap_menu == NULL)
        return NULL;
    free(echap_menu);
    return NULL;
}

echap_menu_t *init_echap_menu(void)
{
    echap_menu_t *echap = malloc(sizeof(echap_menu_t));

    if (echap == NULL)
        return NULL;
    set_all_null(echap, ECHAP_LIB_TYPE);
    return echap;
}
