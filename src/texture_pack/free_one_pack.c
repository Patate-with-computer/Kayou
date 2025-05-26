/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** free_one_pack.c
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics/Texture.h>

sfTexture **free_one_pack(sfTexture **pack)
{
    if (pack == NULL)
        return NULL;
    for (size_t i = 0; pack[i] != NULL; ++i) {
        if (pack[i] == NULL)
            continue;
        sfTexture_destroy(pack[i]);
    }
    free(pack);
    return NULL;
}
