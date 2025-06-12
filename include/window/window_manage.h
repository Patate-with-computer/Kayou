/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** window/window_manage.h
*/

#ifndef WINDOW_MANAGE_H
    #define WINDOW_MANAGE_H
    #include <SFML/Graphics.h>
    #define MAX_FPS 120
#ifndef NB_ADD
    #include "items.h"
#endif
    #define NBR_RECT 100

// other struct
    #include "wolf/struct.h"

static const sfColor floor_color = {131.0, 95.0, 18.0, 255.0};
static const sfColor roof_color = {95.0, 76.0, 34.0, 255.0};
// rgb(95, 76, 34);

// window mode
enum WIN_MODE {
    WIN_WIDTH = 1080,
    WIN_HEIGTH = 820,
    BPP = 32
};
    #define MID_X_WIN ((float)WIN_WIDTH / 2.0)
    #define MID_Y_WIN ((float)WIN_HEIGTH / 2.0)
    #define MID_X_WIN_2 (MID_X_WIN / 2.0)
    #define MID_Y_WIN_2 (MID_Y_WIN / 2.0)

enum ACTUAL_DEMO {
    FIRST_ENEMY,
    TENTACULE,
    MOB_AND_ENEMY,
    ALL_ENEMIES
};

enum ACTUAL_BOSS {
    ATTACK,
    ADD_ENEMY,
    ADD_FOG,
    REMOVE_LIGHT
};

typedef enum {
    MAZE,
    EDIT,
    MAIN_MENU,
    SAVE_MENU,
    SELECT_MENU,
    DELETE_MENU,
    OPTIONS_MENU,
    CREDITS_MENU,
    EXIT_MENU,
    GAME_OVER,
    YOU_WIN
} win_type_t;

// struct to get csfml assets
typedef struct game_csfml_s {
    sfRenderWindow *win;
    sfClock *clock;
    sfClock *clock_timer;
    sfVertexArray *quad;
    sfShader *shadow;
    sfShader *hover;
    sfShader *wp_shader;
    sfShader *brume_shader;
    sfFont *font;
    sfText *text;
    sfCircleShape *circle;
    sfCircleShape *cursor_circle;
    sfSprite *back;
    sfSprite *sprite;
    sfRenderTexture *rend_text;
} game_csfml_t;

// struct for entities of the game
typedef struct game_entities_s {
    player_t *player;
    wall_t *wall;
    target_t *target;
    echap_menu_t *echap_menu;
    cursor_bar_t **cursor;
} game_entities_t;

// window struct
typedef struct game_assets_s {
    game_csfml_t csfml;
    game_entities_t entities;
    sfEvent event;
    sfVector2f scale;
    sfVector2f size;
    win_type_t win_type;
    win_type_t previous_win;
    song_lib_t *song_lib;
    texture_pack_t *text_pack;
    put_txt_t put;
    size_t room;
    float fov;
    float timer;
    actual_window_t *menu;
    size_t nb_save;
    bool is_echap_menu;
    bool is_paused;
    bool is_text;
    bool shadow_room;
    bool restart_clock;
    bool is_brume;
    bool is_god_mode;
    size_t actual_demo;
    size_t actual_boss;
    int vertical_btn;
    int horizontal_btn;
} game_assets_t;

static const char shadow_frag[] = "shaders/shadow.frag";
static const char hover_frag[] = "shaders/hover_save.frag";
static const char wp_frag[] = "shaders/wp_shader.frag";
static const char brum_frag[] = "shaders/light.frag";

game_assets_t *init_window(void);
game_assets_t *free_window(game_assets_t *to_free);
void window_loop(game_assets_t *window);
sfVector2f add_to_vector(sfVector3f src, float y, game_assets_t *win);
void draw_background(game_assets_t *win);
void display_rendertexture(game_assets_t *win);
void check_demo_room(game_assets_t *win);
void move_cheat(game_assets_t *win);
void maze_mode(game_assets_t *win);

#endif
