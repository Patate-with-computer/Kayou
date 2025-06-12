/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** add_item_array.c
*/

#include "window/window_manage.h"
#include "texture_pack.h"
#include "items.h"
#include "map.h"
#include "lib.h"

void add_item_array(game_assets_t *win, add_item_t const *array, size_t nb)
{
    for (size_t i = 0; i < nb; ++i)
        add_specific_item(win, array[i].text_nb, array[i].pos);
}

void add_pnj_array(game_assets_t *win, add_pnj_t const *array, size_t nb)
{
    sfVector2f pos_wall[3] = {{0, 0}, {0, 0}, {0, 0}};
    wall_t *wall = NULL;

    for (size_t i = 0; i < nb; ++i) {
        pos_wall[0] = array[i].pos;
        wall = init_a_wall(pos_wall);
        if (wall == NULL)
            continue;
        wall->item = init_an_items(array[i].text_nb, 0, win->text_pack);
        if (wall->item == NULL)
            return;
        wall->object = IS_ITEM;
        wall->item->pnj_txt = (char *)array[i].str;
        wall->item->anc_time = get_millis(win->csfml.clock);
        add_wall(&win->entities.wall, wall);
    }
}
