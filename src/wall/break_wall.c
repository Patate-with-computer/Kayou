/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** break_wall.c
*/

#include "player.h"
#include "window_manage.h"
#include "map.h"
#include "enemy.h"
#include "song_manage.h"

bool break_wall(player_t *pl, game_assets_t *win, wall_t *weapon)
{
    weapon->weapon->rect.top = TOUCH_TEXT_W(weapon->weapon->size.y);
    weapon->pos1 = weapon->pos2;
    play_song(win, pl->weapon_name, weapon->pos1);
    if (pl->wall_to_break == NULL)
        return false;
    if (!pl->wall_to_break->is_breakable) {
        pl->wall_to_break = NULL;
        return false;
    }
    remove_wall(&win->entities.wall, pl->wall_to_break);
    pl->wall_to_break = NULL;
    return true;
}
