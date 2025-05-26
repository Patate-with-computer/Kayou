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
    #include "type.h"
    #define ITEM_FPS 10
    #define SIZE_ITEM 5.0
    #define DISTANCE_TO_SUPP 15.0
    #define NB_ADD 3
    #define MAX_ADD_ITEM 15
    #define MIN_ADD_ITEM 5

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
} items_t;

typedef struct add_item_s {
    sfVector2f pos;
    size_t text_nb;
} add_item_t;

void display_item(game_assets_t *win, wall_t *item);
void set_rect_item(items_t *item, game_assets_t *win);
wall_t *check_item(game_assets_t *win, player_t *player, wall_t *cpy);
void add_items_wall(wall_t **anc_wall, game_assets_t *win, sfVector2f pos);
items_t *init_an_items(size_t rand_nbr, float to_add,
    texture_pack_t *text_pack);
void add_specific_item(game_assets_t *win, size_t text_nb,
    sfVector2f pos);
void add_item_array(game_assets_t *win, add_item_t const *array, size_t nb);

#endif
