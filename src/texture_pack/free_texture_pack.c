/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** free_texture_pack.c
*/

#include <stdlib.h>
#include <stddef.h>
#include "texture_pack.h"

texture_pack_t *free_texture_pack(texture_pack_t *text_pack)
{
    if (text_pack == NULL)
        return NULL;
    free_one_pack(text_pack->enemy_text);
    free_one_pack(text_pack->items_text);
    free_one_pack(text_pack->target_text);
    free_one_pack(text_pack->weapon_text);
    free_one_pack(text_pack->wall_text);
    free_one_pack(text_pack->attack_text);
    free(text_pack);
    return NULL;
}
