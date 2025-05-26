/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** echap_menu.h
*/

#ifndef ECHAP_MENU_WOLF
    #define ECHAP_MENU_WOLF
    #include <SFML/Graphics.h>

typedef struct game_assets_s game_assets_t;

static const sfColor echap_color = {120, 120, 120, 200};

typedef struct echap_menu_s {
    sfVector2f pos;
} echap_menu_t;

echap_menu_t *init_echap_menu(void);
void set_e_menu(game_assets_t *win);
echap_menu_t *free_echap_menu(echap_menu_t *echap_menu);

#endif
