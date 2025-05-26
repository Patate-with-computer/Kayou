/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** create_song_librairie.c
*/

#include <stdlib.h>
#include "song_manage.h"
#include "lib.h"

song_lib_t *init_lib(void)
{
    song_lib_t *song_lib = malloc(sizeof(song_lib_t));

    if (song_lib == NULL)
        return NULL;
    for (size_t i = 0; i < NB_SONG; ++i)
        song_lib->current[i] = 0;
    set_all_null(song_lib, SONG_LIB_TYPE);
    song_lib->buffer_array = init_sound_buff();
    if (song_lib->buffer_array == NULL)
        return free_song(song_lib);
    song_lib->song = init_all_song_array(song_lib->buffer_array);
    if (song_lib->buffer_array == NULL)
        return free_song(song_lib);
    song_lib->music = sfMusic_createFromFile(music_file);
    if (song_lib->music == NULL)
        return free_song(song_lib);
    return song_lib;
}
