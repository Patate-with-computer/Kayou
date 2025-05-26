/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** init_an_song_array.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include "song_manage.h"

sfSound **init_an_song_array(sfSoundBuffer *buffer)
{
    sfSound **sounds = malloc(sizeof(sfSound *) * (MAX_REPEAT + 1));
    bool error = false;

    if (sounds == NULL)
        return NULL;
    for (size_t i = 0; i < MAX_REPEAT; ++i)
        sounds[i] = NULL;
    for (size_t i = 0; i < MAX_REPEAT; ++i) {
        sounds[i] = sfSound_create();
        if (sounds[i] == NULL) {
            error = true;
            break;
        }
        sfSound_setBuffer(sounds[i], buffer);
    }
    if (error)
        return free_sound_array(sounds);
    return sounds;
}
