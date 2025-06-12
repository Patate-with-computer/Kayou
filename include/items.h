/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** items.h
*/

#ifndef ITEMS_H
    #define ITEMS_H
    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include "wolf/type.h"
    #define ITEM_FPS 10
    #define SIZE_ITEM 5.0
    #define SIZE_BARIL 15.0
    #define DISTANCE_TO_SUPP 15.0
    #define DISTANCE_TO_TALK 30.0
    #define NB_ADD 3
    #define MAX_ADD_ITEM 15
    #define MIN_ADD_ITEM 5

// define for the explosion
    #define DIST_EXPLOD 100.0f
    #define LIFE_TO_RM_EXPLODE 20.0f
typedef struct game_assets_s game_assets_t;
typedef struct wall_s wall_t;
typedef struct texture_pack_s texture_pack_t;
typedef struct player_s player_t;

enum {
    MONEY_TO_ADD,
    LIFE_TO_ADD,
    MAGIC_TO_ADD
};

typedef struct items_s {
    sfFloatRect rect;
    set_texture_t texture;
    sfVector2f size;
    float add_items[NB_ADD];
    float anc_time;
    char *pnj_txt;
} items_t;

typedef struct add_item_s {
    sfVector2f pos;
    size_t text_nb;
} add_item_t;

typedef struct add_pnj_s {
    sfVector2f pos;
    size_t text_nb;
    const char *str;
} add_pnj_t;

void display_item(game_assets_t *win, wall_t *item);
bool set_rect_item(wall_t *wall, game_assets_t *win);
wall_t *check_item(game_assets_t *win, player_t *player, wall_t *cpy);
void add_items_wall(wall_t **anc_wall, game_assets_t *win, sfVector2f pos);
items_t *init_an_items(size_t rand_nbr, float to_add,
    texture_pack_t *text_pack);
void add_specific_item(game_assets_t *win, size_t text_nb,
    sfVector2f pos);

////////////////////////////////////////////////////////////
/// \brief add the item array in the room
///
/// \param win the game assets
/// \param array the array of the items
/// \param nb the number of items
///
////////////////////////////////////////////////////////////
void add_item_array(game_assets_t *win, add_item_t const *array, size_t nb);

////////////////////////////////////////////////////////////
/// \brief add the pnj array in the room
///
/// \param win the game assets
/// \param array the array of the pnjs
/// \param nb the number of pnjs
///
////////////////////////////////////////////////////////////
void add_pnj_array(game_assets_t *win, add_pnj_t const *array, size_t nb);

#endif
