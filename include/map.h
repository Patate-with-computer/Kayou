/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** map.h
*/

#ifndef MAP_H_
    #define MAP_H_
    #include <SFML/System/Vector2.h>
    #include <SFML/System/Vector3.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Texture.h>
    #include <stdbool.h>
    #include "type.h"
    #define SIZE_WALL 30.0
    #define MIN_Y 0.01
    #define BK_STEP 8.0
    #define MAX_SHADOW 150.0

// other struct
typedef struct game_assets_s game_assets_t;
typedef struct player_s player_t;
typedef struct enemy_s enemy_t;
typedef struct weapon_s weapon_t;
typedef struct items_s items_t;
typedef struct enemy_attack_s enemy_attack_t;

// enum to set if a quad is drawable or not
typedef enum {
    NOT_PRINTABLE,
    PRINTABLE
} is_printable_t;

typedef enum wall_object_s {
    IS_WALL,
    IS_ENEMY,
    IS_WEAPON,
    IS_ITEM,
    IS_ATTACK
} wall_object_t;

typedef struct wall_s {
    sfVector2f pos1;
    sfVector2f pos2;
    sfVector2f rect;
    set_texture_t texture;
    enemy_t *enemy;
    weapon_t *weapon;
    items_t *item;
    enemy_attack_t *enemy_attack;
    wall_object_t object;
    float distance;
    is_printable_t printbale;
    sfVector2f size_rect;
    struct wall_s *next;
    bool is_breakable;
    bool hidden;
} wall_t;

typedef struct break_array_s {
    sfVector2f start;
    sfVector2f end;
    size_t nb_text;
} break_array_t;

sfVector3f project_pt(game_assets_t *win, sfVector2f wall_pos,
    is_printable_t *pr);
void display_quad(game_assets_t *win, wall_t *wall);
void free_wall(wall_t *wall);
wall_t *read_file(const char *file_name, sfVector2f *pos);
void set_all_distance(game_assets_t *win, player_t *player, wall_t *wall);
float distance_to_wall(sfVector2f player_pos, wall_t *wall);
void sort_wall(wall_t **path);
float get_distance(sfVector2f pt1, sfVector2f pt2);
wall_t *init_a_wall(sfVector2f new_pos[3]);
void add_wall(wall_t **anc_wal, wall_t *new_wall);
void remove_wall(wall_t **wall, wall_t *enemy);
void free_one_wall(wall_t *wall);
void display_wall(game_assets_t *win, wall_t *wall);
void create_breakable_wall(game_assets_t *win, sfVector2f start,
    sfVector2f end, size_t nb_text);
void add_breakable_array(game_assets_t *win,
    break_array_t const *array, size_t nb_array);
void display_minimap(game_assets_t *assets);

#endif
