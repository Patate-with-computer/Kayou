/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** save_manage.h
*/

#ifndef SAVE_MANAGE_H
    #define SAVE_MANAGE_H
    #include <stdio.h>
    #include <stdbool.h>
    #include <SFML/System/Vector2.h>
    #define DEFAULT_LIFE 100.0
    #define DEFAULT_MONEY 0.0
    #define DEFAULT_MAGIC 0.0
#ifndef GROUND_EVT_H
    #include "ground_evt.h"
#endif
    #define DEFAULT_ROOM RM_INTRO
#ifndef NB_WEAPON
    #include "player.h"
#endif

static const char save_file_mode[] = "%s/save_%lu%s";
static const char save_folder[] = "save";

typedef struct save_manage_s {
    bool get_weapon[NB_WEAPON];
    size_t nb_weapon;
    sfVector2f player_pos;
    float player_life;
    size_t actual_room;
    float money;
    float magic;
} save_manage_t;

static const save_manage_t default_save = {
    {true, 0, 0, 0}, 0, {200.0, 40.0},
    DEFAULT_LIFE, DEFAULT_ROOM,
    DEFAULT_MONEY, DEFAULT_MAGIC
};

void write_a_save(game_assets_t *assets, size_t nb_save);
char *get_filename(size_t nb_save);
void remove_a_save(size_t nb_save);
bool is_file_exist(const char *file_name);
void lunch_a_save(game_assets_t *win, size_t nb_save);
void display_save(game_assets_t *win);

#endif
