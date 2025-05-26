/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** free_sound_array.c
*/

#include <stdlib.h>
#include "song_manage.h"

sfSound **free_sound_array(sfSound **song)
{
    if (song == NULL)
        return NULL;
    for (size_t i = 0; i < MAX_REPEAT; ++i) {
        if (song[i] == NULL)
            continue;
        sfSound_destroy(song[i]);
    }
    free(song);
    return NULL;
}
