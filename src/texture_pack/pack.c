/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** pack.c
*/

#include "texture_pack.h"

sfTexture *pack(set_texture_t set_text, texture_pack_t *text_pack)
{
    sfTexture **all_text[] = {
        text_pack->enemy_text, text_pack->items_text,
        text_pack->target_text, text_pack->wall_text,
        text_pack->weapon_text, text_pack->attack_text
    };

    return all_text[set_text.type][set_text.text_nb];
}
