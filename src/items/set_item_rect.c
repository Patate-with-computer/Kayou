/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** set_item_rect.c
*/

#include <math.h>
#include "items.h"
#include "map.h"
#include "enemy.h"
#include "lib.h"
#include "window/window_manage.h"
#include "texture_pack.h"

static bool remove_item(wall_t *wall, game_assets_t *win)
{
    items_t *item = wall->item;

    if (!(item->texture.text_nb == I_EXPLOSION &&
        item->rect.left + item->size.y >= item->size.x))
        return false;
    remove_wall(&win->entities.wall, wall);
    return true;
}

bool set_rect_item(wall_t *wall, game_assets_t *win)
{
    items_t *item = wall->item;
    float time = get_millis(win->csfml.clock);
    int frame = (time - item->anc_time) * FPS(ITEM);

    for (; frame > 0; --frame) {
        if (remove_item(wall, win))
            return true;
        if (!win->is_paused) {
            item->rect.left = fmodf(item->size.y + item->rect.left,
                item->size.x);
        }
        item->anc_time = time;
    }
    return false;
}
