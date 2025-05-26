/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** set_song_lib_to_null.c
*/

#include <stddef.h>
#include "song_manage.h"

void set_song_lib_to_null(void *song)
{
    song_lib_t *song_lib = (song_lib_t *)song;

    song_lib->buffer_array = NULL;
    song_lib->song = NULL;
    song_lib->music = NULL;
}
