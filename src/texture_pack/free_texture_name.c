/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** free_texture_name.c
*/

#include "texture_pack.h"
#include "lib.h"

void free_texture_name(char *texture_name[MAX_TEXTURE_PACK])
{
    if (texture_name == NULL)
        return;
    for (size_t i = 0; i < MAX_TEXTURE_PACK; ++i)
        MY_FREE(texture_name[i]);
}
