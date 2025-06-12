/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** init_an_items.c
*/

#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "texture_pack.h"
#include "items.h"

items_t *init_an_items(size_t rand_nbr, float to_add,
    texture_pack_t *text_pack)
{
    items_t *items = malloc(sizeof(items_t));
    sfVector2u size = {0, 0};

    if (items == NULL)
        return NULL;
    items->texture = (set_texture_t){ITEMS_TYPE, rand_nbr};
    items->pnj_txt = NULL;
    size = sfTexture_getSize(pack(items->texture, text_pack));
    items->size = (sfVector2f){size.x, size.y};
    memset(items->add_items, 0, sizeof(float) * NB_ADD);
    items->add_items[rand_nbr % 3] = to_add;
    items->anc_time = 0.0;
    items->rect = (sfFloatRect){0, 0, items->size.y, items->size.y};
    return items;
}
