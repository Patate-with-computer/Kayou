/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** window_manage.h
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
typedef struct player_s player_t;
typedef struct wall_s wall_t;
typedef struct texture_pack_s texture_pack_t;
typedef struct target_s target_t;
typedef struct actual_window_s actual_window_t;
typedef struct song_lib_s song_lib_t;
typedef struct echap_menu_s echap_menu_t;
typedef struct cursor_bar_s cursor_bar_t;

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
    sfVertexArray *quad;
    sfShader *shadow;
    sfShader *hover;
    sfShader *wp_shader;
    sfShader *light_shader;
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
    size_t room;
    float fov;
    actual_window_t *menu;
    size_t nb_save;
    bool is_echap_menu;
    bool is_paused;
    bool shadow_room;
    bool restart_clock;
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

#endif
