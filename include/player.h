/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** player.h
*/

#ifndef PLAYER_H
    #define PLAYER_H
    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include "wolf/type.h"
    #define POS(a, b) (POS##_##a##_##b)
    #define POS_Y_TOADD 400
    #define POS_TARGET_TOADD 390
    #define ANGLE (M_PI_2)
    #define FOV 45.6
    #define MAX_DISTANCE_WALL 10.0
    #define MAX_DISTANCE_CHECK 50.0
    #define SIZE_TEXT_PLAYER 32.0
    #define SIZE_TEXT(a) (SIZE_TEXT_##a)
    #define Y_AXCIS 0
    #define X_AXCIS M_PI_2
    #define SIZE_IMG 32
    #define INIT_SPEED 100
    #define SC ((float)(SIZE_IMG) / (float)SIZE_TEXT(PLAYER))
    #define SPEED(speed, clock, a) (speed * (clock - a) / (float)MILLIS_IN_S)
    #define SIZE_WEAPON 15.0
    #define MAX_DIST 100.0
    #define ATTACK_FPS 40.0
    #define TRIANGLE_SIZE 15.0
    #define MAX_CHECK_WALL 2.0
    #define SUS_CHECK_WALL 3.0
    #define NB_WEAPON 4
    #define CAM_SENS 0.005f
    #define JOY_SENS 4.2f
    #define MAX_ANGLE_LIGHT 30.0f

// weapon reload
    #define RELOAD_TIME_ROCK 1000.0
    #define RELOAD_TIME_PISTOL 200.0
    #define RELOAD_TIME_BAG 10.0
    #define RELOAD(a) (RELOAD_TIME_##a)

    #define NB_TEXT_WEAPON 2.0
    #define TOUCH_TEXT_W(a) (a / NB_TEXT_WEAPON * 1.0)
    #define DEF_TEXT_W(a) (a / NB_TEXT_WEAPON * 0.0)
    #define CONV_DEG(a) (a * 180.0 / M_PI)

typedef struct game_assets_s game_assets_t;
typedef struct texture_pack_s texture_pack_t;
typedef struct wall_s wall_t;

// MINIMAP
    #define SIZE_MINIMAP 150.0
    #define MAX_DIST_SHADOW 50.0
    #define SIZE_PLAYER 4.0
    #define SIZE_ENEMY_MMP 4.0
    #define SIZE_ATK_MMP 2.0
static const sfColor player_color = {120, 255, 50, 255};
static const sfColor enemies_color[2] = {{255, 120, 50, 255},
    {255, 200, 100, 255}};
static const sfColor back_color = {0, 0, 0, 150};

// ATH
    #define SIZE_ATH 100.0
    #define SIZE_TEXT_ATH 60.0
    #define TO_ADD_ATH 20.0
    #define SIZE_PRINT_ATH 75.0
    #define TO_ADD_TEXTATH 10.0
float print_one_texture(sfTexture *text, sfVector2f pos, game_assets_t *win);
void print_ath(game_assets_t *win);
float print_one_text(float info, const char *s, sfVector2f pos,
    game_assets_t *win);
static const sfColor ath_text_color = {200, 255, 225, 255};


// WEAPON PURCHASE
    #define SIZE_TEXT_WP 32.0
    #define SIZE_RECT_WP 100.0
    #define START_Y_WP 200.0
    #define START_X_WP 50.0
    #define BETWENN_WP 30.0
    #define SIZE_TEXT_PRICE 40.0
void display_one_weapon(game_assets_t *win, sfVector2f pos, size_t nb_weapon);
void display_price(game_assets_t *win, sfVector2f pos, size_t nb_weapon);
static const sfColor price_color = {180, 200, 180, 255};


typedef struct weapon_s {
    sfFloatRect rect;
    sfVector2f size;
    size_t text_purchase;
    float price;
    float reload_time;
    float anc_reload_time;
    bool is_attacking;
    float attack;
    float anc_time;
    float max_dist;
    float init_max_dist;
    float tr_size;
    float init_tr;
    float mana_to_rm;
} weapon_t;

typedef enum {
    KAYOUX_WP,
    PISTOL_WP,
    LIGHTING_WP,
    BAG_WP
} weapon_name_t;

typedef struct weapon_config_s {
    size_t nb_text;
    size_t nb_text_purchase;
    float price;
    float attack;
    float max_dist;
    float init_tr;
    float reload_time;
    float mana;
} weapon_config_t;

typedef struct player_s {
    sfVector2f pos;
    wall_t *weapon[NB_WEAPON];
    bool get_weapon[NB_WEAPON];
    wall_t *wall_to_break;
    wall_t *wall_to_lock;
    size_t weapon_name;
    float anc_time;
    float arrondie;
    float angle;
    float focal;
    float speed;
    float life;
    float money;
    float magic;
} player_t;


void free_player(player_t *player);
player_t *init_player(void);
wall_t *init_weapon(size_t nb_text, float attack, texture_pack_t *text_pack);
void move_player(game_assets_t *win);
void set_rect_weapon(weapon_t *weapon, game_assets_t *win);
void display_weapon(game_assets_t *win, wall_t *weapon);
bool set_weapon_pos(game_assets_t *win, wall_t *weapon);
void add_all_weapon(game_assets_t *win);
bool point_in_triangle(sfVector2f point, sfVector2f a,
    sfVector2f b, sfVector2f c);
void change_camera_angle(game_assets_t *win);
float get_max(game_assets_t *win, wall_t *weapon);
void move_to_a_pos(game_assets_t *win, float to_add,
    bool neg, float speed);
sfBool check_weapon_exist(player_t *player);
bool break_wall(player_t *pl, game_assets_t *win, wall_t *weapon);
char *get_timer_str(game_assets_t *win);
void set_lock_wall(game_assets_t *win);

#endif
