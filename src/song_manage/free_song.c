/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** free_song.c
*/

#include <stdlib.h>
#include "song_manage.h"

song_lib_t *free_song(song_lib_t *song)
{
    if (song == NULL)
        return NULL;
    (void)free_sound_buffer(song->buffer_array);
    (void)free_all_song_array(song->song);
    if (song->music != NULL)
        sfMusic_destroy(song->music);
    free(song);
    return NULL;
}
