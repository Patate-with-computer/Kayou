/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** get_texture_size.c
*/

#include "texture_pack.h"
#include "map.h"

sfVector2f get_texture_size(set_texture_t text, texture_pack_t *pk)
{
    sfVector2u size = sfTexture_getSize(pack(text, pk));

    return (sfVector2f){(float)size.x, (float)size.y};
}
