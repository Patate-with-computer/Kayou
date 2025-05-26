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
#include "window_manage.h"

void set_rect_item(items_t *item, game_assets_t *win)
{
    float time = get_millis(win->csfml.clock);
    int frame = (time - item->anc_time) * FPS(ITEM);

    for (; frame > 0; --frame) {
        item->rect.left = fmodf(item->size.y + item->rect.left, item->size.x);
        item->anc_time = time;
    }
}
