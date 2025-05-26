/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** check_item.c
*/

#include "items.h"
#include "player.h"
#include "map.h"
#include "window_manage.h"
#include "song_manage.h"

static void add_to_player(items_t *item, player_t *player)
{
    player->life += item->add_items[LIFE_TO_ADD];
    player->money += item->add_items[MONEY_TO_ADD];
    player->magic += item->add_items[MAGIC_TO_ADD];
}

wall_t *check_item(game_assets_t *win, player_t *player, wall_t *cpy)
{
    wall_t *tmp = NULL;

    cpy->distance = get_distance(player->pos, cpy->pos1);
    if (cpy->distance <= DISTANCE_TO_SUPP) {
        tmp = cpy->next;
        add_to_player(cpy->item, win->entities.player);
        play_song(win, SG_MONEY, cpy->pos1);
        remove_wall(&win->entities.wall, cpy);
        return tmp;
    }
    set_rect_item(cpy->item, win);
    return cpy;
}
