/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** set_all_texture.c
*/

#include "map.h"
#include "enemy.h"
#include "lib.h"

void set_all_texture(game_assets_t *win)
{
    float act_time = get_millis(win->csfml.clock);

    for (wall_t *w = win->entities.wall; w != NULL; w = w->next) {
        if (w->object != IS_ENEMY)
            continue;
        if (remove_life(&win->entities.wall, w, win))
            return;
        if (w->enemy->is_touch && act_time -
                w->enemy->anc_text_time >= DURATION_TOUCH) {
            w->enemy->is_touch = false;
        }
        if (w->enemy->is_touch)
            w->enemy->rect.top = TOUCH_TEXT(w->enemy->size.y);
        else {
            w->enemy->rect.top = DEFAULT_TEXT(w->enemy->size.y);
            w->enemy->anc_text_time = act_time;
        }
    }
}
