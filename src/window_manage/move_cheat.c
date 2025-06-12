/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** move_cheat.c
*/

#include "file_manage.h"
#include "enemy.h"
#include "window/window_manage.h"
#include "screen_text.h"
#include "ground_evt.h"
#include "items.h"
#include "texture_pack.h"
#include "map.h"

static void add_enemies(sfVector2f pos, game_assets_t *win, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        add_an_enemy(i % 3, pos, win, 120.0);
}

static void all_check(game_assets_t *win, wall_t *cheat)
{
    if (cheat->enemy->life <= cheat->enemy->max_life * 3.0 / 4.0
        && win->actual_boss == ATTACK) {
        add_enemies(cheat->pos1, win, 1);
        ++win->actual_boss;
    }
    if (cheat->enemy->life <= cheat->enemy->max_life / 2.0 &&
        win->actual_boss == ADD_ENEMY) {
        add_enemies(cheat->pos1, win, 2);
        win->is_brume = true;
        ++win->actual_boss;
    }
    if (cheat->enemy->life <= cheat->enemy->max_life / 4.0 &&
        win->actual_boss == ADD_FOG) {
        add_enemies(cheat->pos1, win, 3);
        win->shadow_room = true;
        ++win->actual_boss;
    }
}

void move_cheat(game_assets_t *win)
{
    wall_t *cheat = NULL;

    if (win->room != RM_BOSS)
        return;
    for (wall_t *w = win->entities.wall; w != NULL; w = w->next) {
        if (w->object == IS_ENEMY && w->texture.text_nb == E_CHEAT)
            cheat = w;
    }
    if (cheat == NULL)
        return;
    all_check(win, cheat);
}
