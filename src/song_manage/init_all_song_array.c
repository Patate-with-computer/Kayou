/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** init_all_song_array.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include "song_manage.h"

sfSound ***init_all_song_array(sfSoundBuffer **buffer)
{
    sfSound ***songs = malloc(sizeof(sfSound **) * (NB_SONG + 1));
    bool error = false;

    if (songs == NULL)
        return NULL;
    for (size_t i = 0; i < NB_SONG; ++i)
        songs[i] = NULL;
    for (size_t i = 0; i < NB_SONG; ++i) {
        songs[i] = init_an_song_array(buffer[i]);
        if (songs[i] == NULL) {
            error = true;
            break;
        }
    }
    if (error)
        return free_all_song_array(songs);
    return songs;
}
