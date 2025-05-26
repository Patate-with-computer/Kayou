/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** enemy.h
*/

#ifndef ENEMY_H
    #define ENEMY_H
    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include "type.h"
    #define SIZE_ENEMY 15.0
    #define SIZE_ENEMY_ATK 15.0
    #define SIZE_FONT 3.0
    #define FTSZ(ptz) (ptz * SIZE_FONT / SIZE_WALL)
    #define MAX_FONT_SIZE 100.0
    #define ENEMY(a) ("assets/enemy/"#a WOLF_TERM)
    #define FONT_STR "assets/font/font.ttf"
#ifndef MAX_FPS
    #include "window_manage.h"
#endif
    #define ANIMATION_FPS 1.0
    #define ATTACK_ENEMY_FPS 20.0
    #define DURATION_TOUCH 200
    #define FPS(a) ((a##_FPS) / (float)MILLIS_IN_S)
    #define MIN_DISTANCE_ATTACK_PROX_ENEMY 10.0
    #define MIN_DISTANCE_ATTACK_LONG_ENEMY 100.0
    #define MIN_DISTANCE_ATTACK_BOSS_ENEMY 800.0
    #define DIST_ATK(a) (MIN_DISTANCE_ATTACK_##a##_ENEMY)
    #define MIN_DIST_CHECK_ATTACK 5.0
    #define NB_TEXT 3.0
    #define TOUCH_TEXT(a) (a / NB_TEXT * 1.0)
    #define DEFAULT_TEXT(a) (a / NB_TEXT * 0.0)
    #define TIME_TO_WAIT 2000.0
    #define MAX_TIME_ADD_TO_WAIT 500.0
    #define SPEED_ENEMY 50
    #define MAX_CHECK_ENEMY 80.0
    #define MAX_DIST_CHECK 500.0
    #define TO_CHANGE_ANGLE 40.0

// LIFE BAR
    #define SIZE_LIFE_BAR 1.4
    #define SIZE_TO_REMOVE_LIFEBAR 3.0
static const sfColor back_lifebar = {0, 0, 0, 50.0};

typedef struct game_assets_s game_assets_t;
typedef struct wall_s wall_t;

typedef struct enemy_attack_s {
    sfFloatRect rect;
    sfVector2f size;
    sfVector2f init_pos;
    float angle;
    float max_dist;
    float speed;
    float anc_time;
    float anc_time_move;
    float life_to_rm;
    float reload_time;
} enemy_attack_t;

extern const enemy_attack_t enemy_attack_list[];

typedef struct enemy_s {
    sfFloatRect rect;
    sfVector2f size;
    bool is_touch;
    bool prev_touch;
    float life_to_rm;
    float anc_time;
    float life;
    float max_life;
    float anc_text_time;
    float wait_time;
    float angle;
    float anc_time_move;
} enemy_t;

// color for the enemies
static const sfColor font_color = {228, 56, 127, 255};
static const float distance_attack[] = {DIST_ATK(PROX), DIST_ATK(LONG)};

void display_enemy(game_assets_t *win, wall_t *enemy);
void read_file_enemy(const char *file_name, game_assets_t *win);
void convert_enemy(const char *file_name);
void set_rect(enemy_t *enemy, game_assets_t *win);
void set_all_texture(game_assets_t *win);
bool remove_life(wall_t **wall, wall_t *enemy, game_assets_t *win);
void set_texture_and_var(enemy_t *enemy, float life,
    texture_pack_t *text_pack, set_texture_t text);
void add_an_enemy(size_t nb_en, sfVector2f pos,
    game_assets_t *win, float life);
void add_an_attack(wall_t *en_in, game_assets_t *win);
void display_attack(game_assets_t *win, wall_t *attack);
void set_rect_attack(enemy_attack_t *attack, game_assets_t *win);
void move_all_attack(game_assets_t *win);
size_t count_enemy(game_assets_t *win);
void print_life_str(game_assets_t *win, wall_t *wall, sfVector3f pr);
void move_an_enemy(game_assets_t *win, wall_t *enemy);

#endif
