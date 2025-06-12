/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** check_item.c
*/

#include "items.h"
#include "player.h"
#include "map.h"
#include "window/window_manage.h"
#include "song_manage.h"
#include "enemy.h"
#include "texture_pack.h"
#include "event_manage.h"
#include "screen_text.h"

static void add_to_player(items_t *item, player_t *player)
{
    player->life += item->add_items[LIFE_TO_ADD];
    player->money += item->add_items[MONEY_TO_ADD];
    player->magic += item->add_items[MAGIC_TO_ADD];
}

static void check_explosion(game_assets_t *win, wall_t *explosion)
{
    wall_t *wall = win->entities.wall;

    for (; wall != NULL; wall = wall->next) {
        if (wall->object != IS_ENEMY)
            continue;
        if (get_distance(wall->pos1, explosion->pos1) <= DIST_EXPLOD) {
            wall->enemy->is_touch = true;
            wall->enemy->life_to_rm = LIFE_TO_RM_EXPLODE;
        }
    }
}

static wall_t *supp_item(game_assets_t *win, wall_t *tmp, wall_t *cpy)
{
    if (cpy->distance <= DISTANCE_TO_SUPP) {
        tmp = cpy->next;
        add_to_player(cpy->item, win->entities.player);
        play_song(win, SG_MONEY, cpy->pos1);
        remove_wall(&win->entities.wall, cpy);
        return tmp;
    }
    return cpy;
}

wall_t *check_item(game_assets_t *win, player_t *player, wall_t *cpy)
{
    wall_t *tmp = cpy->next;

    cpy->distance = get_distance(player->pos, cpy->pos1);
    if (set_rect_item(cpy, win))
        return tmp;
    if (cpy->item->texture.text_nb == I_EXPLOSION)
        check_explosion(win, cpy);
    if (cpy->distance <= DISTANCE_TO_TALK && cpy->item->pnj_txt != NULL
        && get_a_key(win, TALK) && win->put.txt == NULL) {
        win->put.mode = LITLE_MODE;
        win->put.txt = cpy->item->pnj_txt;
    }
    if (cpy->item->texture.text_nb > 2)
        return cpy;
    return supp_item(win, tmp, cpy);
}
