/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** ground_evt.h
*/

#ifndef GROUND_EVT_H
    #define GROUND_EVT_H
    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #define RESET 0

typedef struct game_assets_s game_assets_t;

enum {
    RM_INTRO,
    RM_HALLWAY,
    RM_HALLWAY_1,
    RM_HALLWAY_2,
    RM_SECRET,
    RM_DIAGMAP,
    RM_LABYRINTH,
    RM_HELL_ROOM,
    RM_BOSS
};

typedef struct ground_evt_s {
    void (*func)(game_assets_t *win, sfVector2f reset);
    sfFloatRect rect;
    size_t room;
    sfVector2f reset;
} ground_evt_t;

extern const ground_evt_t grd[];

bool is_in_rect(sfVector2f pos, sfFloatRect rect);

void set_room_by_ground_evt(game_assets_t *win);
void set_intro(game_assets_t *win, sfVector2f reset);
void set_hallway(game_assets_t *win, sfVector2f reset);
void set_hallway1(game_assets_t *win, sfVector2f reset);
void set_hallway2(game_assets_t *win, sfVector2f reset);
void set_secret(game_assets_t *win, sfVector2f reset);
void set_labyrinth(game_assets_t *win, sfVector2f reset);
void set_diag_map(game_assets_t *win, sfVector2f reset);
void set_hell_room(game_assets_t *win, sfVector2f reset);
void set_boss(game_assets_t *win, sfVector2f reset);

#endif
