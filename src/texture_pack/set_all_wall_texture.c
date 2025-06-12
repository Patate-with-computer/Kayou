/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** set_all_wall_texture.c
*/

#include "enemy.h"
#include "window/window_manage.h"
#include "texture_pack.h"
#include "player.h"
#include "buttons.h"
#include "target.h"
#include "map.h"

static void wall_loop(game_assets_t *win, texture_pack_t *pk)
{
    wall_t *wall = win->entities.wall;

    for (; wall != NULL; wall = wall->next) {
        if (wall->object == IS_ITEM) {
            wall->item->size = get_texture_size(wall->item->texture, pk);
            wall->item->rect = (sfFloatRect){0, 0, wall->item->size.y,
                wall->item->size.y};
        }
        if (wall->object == IS_ENEMY) {
            wall->enemy->size = get_texture_size(wall->texture, pk);
            wall->enemy->rect = (sfFloatRect){0, 0,
                wall->enemy->size.y / NB_TEXT, wall->enemy->size.y / NB_TEXT};
        }
        if (wall->object == IS_ATTACK) {
            wall->enemy_attack->size = get_texture_size(wall->texture, pk);
            wall->enemy_attack->rect = (sfFloatRect){0, 0,
                wall->enemy_attack->size.y, wall->enemy_attack->size.y};
        }
    }
}

void set_all_wall_texture(game_assets_t *win)
{
    texture_pack_t *pk = win->text_pack;
    wall_t *wp = NULL;

    for (size_t i = 0; i < NB_WEAPON; ++i) {
        wp = win->entities.player->weapon[i];
        if (wp == NULL)
            continue;
        wp->weapon->size = get_texture_size(wp->texture, pk);
        wp->weapon->rect = (sfFloatRect){0.0, 0.0,
            wp->weapon->size.y / NB_TEXT_WEAPON,
            wp->weapon->size.y / NB_TEXT_WEAPON};
    }
    wall_loop(win, pk);
}
