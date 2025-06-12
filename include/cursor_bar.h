/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** cursor_bar.h
*/

#ifndef CURSOR_BAR_H
    #define CURSOR_BAR_H
    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #define END_CURSOR -1
    #define WIDTH_CURSOR 200.0f
    #define TEXT_ADD 30.0f
    #define HEIGHT_CURSOR 10.0f
    #define SIZE_CIRCLE_CURSOR 15.0f
    #define SIZE_TXT_CURSOR 50
#ifndef WINDOW_MANAGE_H
    #include "window/window_manage.h"
#endif

typedef struct game_assets_s game_assets_t;

static const sfColor color_bar = {120, 150, 120, 255};

typedef struct cursor_bar_s {
    sfVector2f pos;
    float circle_pos;
    float percent;
} cursor_bar_t;

typedef enum {
    MUSIC_CURSOR,
    SOUNDS_CURSOR
} cursor_name_t;

static const cursor_bar_t cursor_array[] = {
    {{MID_X_WIN + MID_X_WIN_2 / 2.0, 350}, 100, 0},
    {{MID_X_WIN + MID_X_WIN_2 / 2.0, 550}, 100, 0},
    {{END_CURSOR, END_CURSOR}, END_CURSOR, END_CURSOR}
};

cursor_bar_t **init_cursors(void);
cursor_bar_t **free_cursors(cursor_bar_t **cursor);
void display_cursor(game_assets_t *win, size_t nb);
void move_circle(game_assets_t *win, size_t nb);
void move_circle_joystick(game_assets_t *win, size_t nb);

#endif
