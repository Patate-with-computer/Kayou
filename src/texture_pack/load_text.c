/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** load_text.c
*/

#include "map.h"
#include "enemy.h"
#include "window/window_manage.h"
#include "texture_pack.h"
#include "player.h"
#include "buttons.h"
#include "target.h"

static void set_target_sprite(game_assets_t *win)
{
    sfVector2f middle = {0.0, 0.0};
    sfTexture *texture = pack((set_texture_t){TARGET_TYPE, T_TARGET},
        win->text_pack);

    win->entities.target->size_x = (float)sfTexture_getSize(texture).x;
    middle.x = win->entities.target->size_x / 2.0;
    middle.y = win->entities.target->size_x / 2.0;
    sfSprite_setTexture(win->entities.target->sprite, texture, sfTrue);
    sfSprite_setOrigin(win->entities.target->sprite, middle);
    win->entities.target->print_target = true;
}

void load_text(game_assets_t *win, char const *text)
{
    texture_pack_t *tmp = init_texture_pack(text);

    if (tmp == NULL)
        return;
    free_texture_pack(win->text_pack);
    win->text_pack = tmp;
    set_target_sprite(win);
    set_all_wall_texture(win);
    destroy_menu_struct(win->menu);
    win->menu = init_window_data(tmp);
}
