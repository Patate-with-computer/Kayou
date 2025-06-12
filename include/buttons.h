/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** buttons.h
*/

#ifndef BUTTONS_H
    #define BUTTONS_H
    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include "wolf/type.h"
    #define NB_BUTTON 17
    #define SIZE_X (1200 / 3)
    #define SIZE_Y (750 / 5)
    #define NBR_MAX_SAVE 3
    #define SIZE_TEXT_SAVE 100
    #define SIZE_RECT_SAVE 200
    #define POS_Y_SAVE 300
    #define CREDITS_TXT "Press any key to echap"

// other struct
    #include "wolf/struct.h"

typedef struct button_info_s {
    int pos_x_text;
    int pos_y_text;
    int pos_x_win;
    int pos_y_win;
} button_info_t;

enum {
    PLAY_BNT, MENU_BTN, LUNCH_BTN, REMOVE_BTN,
    EPITECH_BTN, DEFAULT_BTN,
    OPTION_BNT = 6,
    CONTINUE_BTN = 7,
    BACK_BTN = 8,
    MUSIC_BUTTON = 10,
    SOUNDS_BTN,
    CREDIT_BTN,
    QUIT_BTN,
    RESTART_BTN,
    MENU_RESTART_BNT
};

#ifndef WINDOW_MANAGE_H
    #include "window/window_manage.h"
#endif

static const button_info_t button_array[NB_BUTTON] =
{
    {0, 2, MID_X_WIN, 100}, // -> button PLAY
    {1, 4, MID_X_WIN, 500}, // -> button MENU
    {0, 1, MID_X_WIN_2, 600}, // -> button LAUNCH
    {1, 0, MID_X_WIN + MID_X_WIN_2, 600}, // -> button REMOVE
    {1, 2, MID_X_WIN_2, 720}, // -> button EPITECH
    {1, 1, MID_X_WIN + MID_X_WIN_2, 720}, // -> button DEFAULT
    {2, 1, MID_X_WIN, 300}, // -> button OPTION
    {0, 0, MID_X_WIN, 100}, // -> button CONTINUE
    {0, 4, MID_X_WIN, 100}, // -> button BACK
    {2, 3, MID_X_WIN, 200}, // -> button 1
    {0, 3, MID_X_WIN_2, 350}, // -> button MUSIC
    {1, 3, MID_X_WIN_2, 550}, // -> button SOUNDS
    {2, 0, MID_X_WIN, 500}, // -> button CREDIT
    {2, 2, MID_X_WIN, 700}, // -> button QUIT
    {2, 4, MID_X_WIN_2, 600}, // -> button RESTART
    {1, 4, MID_X_WIN + MID_X_WIN_2, 600}, // -> button MENU_restart
    {-1, -1, -1, -1}
};

typedef struct buttons_s {
    char const *name;
    sfSprite *sprite;
    sfIntRect texture_pos;
    sfVector2f button_pos;
    sfIntRect button_area;
    int hovered;
} buttons_t;

typedef struct menu_background_s {
    sfTexture *b;
    sfSprite *s;
} menu_background_t;

typedef struct actual_window_s {
    set_texture_t buttons_texture;
    menu_background_t *win_back;
    buttons_t **buttons;
} actual_window_t;

buttons_t **init_buttons(sfTexture *texture);

actual_window_t *init_window_data(texture_pack_t *text_pack);

void launcher(game_assets_t *win);

void check_launcher_hover(game_assets_t *window);

void destroy_menu_struct(actual_window_t *menu);

bool check_button_hover(game_assets_t *window, buttons_t *button);

void save_menu(game_assets_t *win);

void check_save_menu_hover(game_assets_t *window);

void print_button(game_assets_t *win, size_t nb_btn);

void blink_text(game_assets_t *window, char *text, sfColor col, size_t size);

void credit_menu(game_assets_t *window);

void exit_menu(game_assets_t *win);

void check_exit_menu_hover(game_assets_t *window);

void opt_menu(game_assets_t *win);

void display_background(game_assets_t *win);

void game_over(game_assets_t *win);

void you_win(game_assets_t *win);


#endif
