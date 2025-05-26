/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** free_all_song_array.c
*/

#include <stdlib.h>
#include "song_manage.h"

sfSound ***free_all_song_array(sfSound ***sounds)
{
    if (sounds == NULL)
        return NULL;
    for (size_t i = 0; i < NB_SONG; ++i)
        (void)free_sound_array(sounds[i]);
    free(sounds);
    return NULL;
}
