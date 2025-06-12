/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** event_manage.h
*/

#ifndef EVENT_MANAGE_H
    #define EVENT_MANAGE_H
    #include <SFML/Graphics.h>

// other struct
typedef struct game_assets_s game_assets_t;

enum {
    BUTTON_CROIX,
    BUTTON_CIRCLE,
    BUTTON_TRIANGLE,
    BUTTON_SQUARE,
    BUTTON_L1,
    BUTTON_R1,
    BUTTON_L2,
    BUTTON_OPTION = 9
};

sfBool get_key_attack(void);
sfBool get_confirm_key(void);
void event_manage(game_assets_t *window);
void get_win_scale(game_assets_t *win);
sfBool get_joy_button(size_t nb_joy, size_t button);
sfBool get_one_click(void);
sfBool get_one_button_click(sfKeyCode key);
sfBool get_one_e(void);
sfBool get_one_escape(void);
float get_mov_joy(size_t joy_nb, sfJoystickAxis axis);
void set_vertical_btn(game_assets_t *win);
void set_horizontal_btn(game_assets_t *win);

#endif
