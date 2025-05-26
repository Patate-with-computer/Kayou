/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** init_sound_buff.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "song_manage.h"

static const char *song_links[NB_SONG] = {
    "kayou.mp3",
    "pistol_shoot.mp3",
    "bag_shoot.mp3",
    "light_shot.mp3",
    "money.mp3",
    "button.mp3",
    "dead.mp3",
    "touch.mp3"
};

static char *get_file_name(char const *file)
{
    static char name[BUFSIZ] = {0};

    memset(name, '\0', sizeof(char) * BUFSIZ);
    sprintf(name, "assets/song/%s", file);
    return name;
}

sfSoundBuffer **init_sound_buff(void)
{
    sfSoundBuffer **buffer = malloc(sizeof(sfSoundBuffer *) * (NB_SONG + 1));
    bool error = false;

    if (buffer == NULL)
        return NULL;
    for (size_t i = 0; i < NB_SONG; ++i)
        buffer[i] = NULL;
    for (size_t i = 0; i < NB_SONG; ++i) {
        buffer[i] = sfSoundBuffer_createFromFile(
            get_file_name(song_links[i]));
        if (buffer[i] == NULL) {
            error = true;
            break;
        }
    }
    if (error)
        return free_sound_buffer(buffer);
    return buffer;
}
