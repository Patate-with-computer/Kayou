/*
** EPITECH PROJECT, 2025
** include
** File description:
** include
*/

#ifndef LIB_H
    #define LIB_H
    #include <stdlib.h>
    #include <stddef.h>
    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #define MY_FREE(ptr) ((ptr == NULL) ? (0) : (free(ptr)))
    #define MILLIS_IN_S 1000

typedef enum type_to_set_s {
    SONG_LIB_TYPE,
    WIN_LIB_TYPE,
    TEXTPACK_LIB_TYPE,
    PLAYER_LIB_TYPE,
    MENU_LIB_TYPE,
    ECHAP_LIB_TYPE
} type_to_set_t;

float get_millis(sfClock *clock);
void set_all_null(void *struct_to_null, type_to_set_t type);
void set_song_lib_to_null(void *song);
void null_game_assets_struct(void *win);
void null_texture_pack_struct(void *txt_pack);
void null_player_struct(void *to_null);
void set_all_null_menu(void *to_null);
void null_echap_menu(void *echap);
size_t randint(size_t max);

typedef struct wall_s wall_t;
typedef struct player_s player_t;
float raycast_to_walls(wall_t *walls, sfVector2f origin,
    float angle, float max_dist);
float update_closest_distance(sfVector2f origin, sfVector2f dir,
    wall_t *wall, float max_dist);
float get_ray_segment_distance(sfVector2f origin, sfVector2f dir,
    sfVector2f p1, sfVector2f p2);
float get_wall_visibility_angle(wall_t *wall, player_t *pl, wall_t *walls);

#endif
