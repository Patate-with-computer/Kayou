/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** null_texture_pack_struct.c
*/

#include <stddef.h>
#include "texture_pack.h"

void null_texture_pack_struct(void *txt_pack)
{
    texture_pack_t *texture_pack = (texture_pack_t *)txt_pack;

    texture_pack->enemy_text = NULL;
    texture_pack->items_text = NULL;
    texture_pack->target_text = NULL;
    texture_pack->weapon_text = NULL;
    texture_pack->wall_text = NULL;
    texture_pack->attack_text = NULL;
}
