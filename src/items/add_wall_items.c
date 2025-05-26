/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** add_wall_items.c
*/

#include <stdlib.h>
#include "window_manage.h"
#include "items.h"
#include "map.h"

size_t randint(size_t max)
{
    return rand() % max;
}

void add_items_wall(wall_t **anc_wall, game_assets_t *win, sfVector2f pos)
{
    sfVector2f pos_wall[3] = {pos, {0.0, 0.0}, {0.0, 0.0}};
    wall_t *wall = init_a_wall(pos_wall);
    size_t rand_item = randint(NB_ADD);
    size_t to_add = randint(MAX_ADD_ITEM - MIN_ADD_ITEM) + MIN_ADD_ITEM;

    if (wall == NULL)
        return;
    wall->item = init_an_items(rand_item, (float)to_add, win->text_pack);
    wall->object = IS_ITEM;
    add_wall(anc_wall, wall);
}

void add_specific_item(game_assets_t *win, size_t text_nb,
    sfVector2f pos)
{
    sfVector2f pos_wall[3] = {pos, {0.0, 0.0}, {0.0, 0.0}};
    wall_t *wall = init_a_wall(pos_wall);

    if (wall == NULL)
        return;
    wall->item = init_an_items(text_nb, 10, win->text_pack);
    wall->object = IS_ITEM;
    add_wall(&win->entities.wall, wall);
}
