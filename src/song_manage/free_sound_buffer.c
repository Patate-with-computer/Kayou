/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** free_sound_buffer.c
*/

#include <stdlib.h>
#include "song_manage.h"

sfSoundBuffer **free_sound_buffer(sfSoundBuffer **buffer)
{
    if (buffer == NULL)
        return NULL;
    for (size_t i = 0; i < NB_SONG; ++i) {
        if (buffer[i] == NULL)
            continue;
        sfSoundBuffer_destroy(buffer[i]);
    }
    free(buffer);
    return NULL;
}
