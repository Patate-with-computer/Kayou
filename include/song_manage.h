/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** song_manage.h
*/

#ifndef WOLF_SONG_MANAGE
    #define WOLF_SONG_MANAGE
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #define MAX_REPEAT 5
    #define NB_SONG 9

typedef struct player_s player_t;
typedef struct game_assets_s game_assets_t;

static const char music_file[] = "assets/song/music.mp3";

typedef enum song_list_s {
    SG_KAYOU,
    SG_PISTOL,
    SG_BAG,
    SG_LIGHT,
    SG_MONEY,
    SG_BUTTON,
    SG_DEAD,
    SG_TOUCH,
    SG_EXPLODE
} song_list_t;

typedef struct song_lib_s {
    sfSoundBuffer **buffer_array;
    sfSound ***song;
    sfMusic *music;
    size_t current[NB_SONG];
} song_lib_t;

song_lib_t *init_lib(void);
song_lib_t *free_song(song_lib_t *song);
sfSoundBuffer **free_sound_buffer(sfSoundBuffer **buffer);
sfSoundBuffer **init_sound_buff(void);
sfSound **free_sound_array(sfSound **song);
sfSound ***free_all_song_array(sfSound ***sounds);
sfSound **init_an_song_array(sfSoundBuffer *buffer);
sfSound ***init_all_song_array(sfSoundBuffer **buffer);
sfSound **free_sound_array(sfSound **song);
void set_volume(game_assets_t *win);

////////////////////////////////////////////////////////////
/// \brief function to play a song
///
/// call this function to play a specific song (and put it in space)
///
/// \param win the game assets
/// \param nbr_song the song number (cf song_list_t enum)
/// \param relative the position of the song in space (if you want
///                 normal song you put the player position)
///
////////////////////////////////////////////////////////////
void play_song(game_assets_t *win, song_list_t nbr_song, sfVector2f relative);


void set_player_song(player_t *player);

#endif
