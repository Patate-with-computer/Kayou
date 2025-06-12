/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** play_song.c
*/

#include <math.h>
#include "window/window_manage.h"
#include "song_manage.h"
#include "player.h"
#include "cursor_bar.h"

void set_volume(game_assets_t *win)
{
    sfVector2f pos = win->entities.player->pos;

    sfMusic_setPosition(win->song_lib->music, (sfVector3f){pos.x, pos.y, 0});
    sfMusic_setVolume(win->song_lib->music,
        win->entities.cursor[MUSIC_CURSOR]->percent);
}

void set_player_song(player_t *player)
{
    sfVector2f pos_player = player->pos;
    float angle = player->angle;
    sfVector3f forward = {cosf(angle), 0.0f, sinf(angle)};

    sfListener_setPosition((sfVector3f){pos_player.x, pos_player.y, 0.0f});
    sfListener_setDirection(forward);
}

void play_song(game_assets_t *win, song_list_t nbr_song, sfVector2f relative)
{
    song_lib_t *song_lib = win->song_lib;
    size_t current = song_lib->current[nbr_song];
    sfSound *sound = song_lib->song[nbr_song][current];

    sfSound_setPosition(sound, (sfVector3f){relative.x, relative.y, 0.0f});
    sfSound_setRelativeToListener(sound, sfFalse);
    sfSound_setAttenuation(sound, 0.5f);
    sfSound_setMinDistance(sound, 5.0f);
    sfSound_play(sound);
    sfSound_setVolume(sound, win->entities.cursor[SOUNDS_CURSOR]->percent);
    song_lib->current[nbr_song] = (current + 1) % MAX_REPEAT;
}
