/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** remove_life.c
*/

#include "map.h"
#include "enemy.h"
#include "song_manage.h"

#include "lib.h"
#include "map.h"
void remove_wall(wall_t **wall, wall_t *enemy)
{
    wall_t *prev = *wall;
    wall_t *head = *wall;

    if (head == NULL)
        return;
    if (enemy == *wall) {
        *wall = (*wall)->next;
        return free_one_wall(enemy);
    }
    for (head = head->next; head != NULL; head = head->next) {
        if (enemy == head) {
            prev->next = head->next;
            return free_one_wall(enemy);
        }
        prev = head;
    }
}

#include "items.h"
#include "player.h"
bool remove_life(wall_t **wall, wall_t *enemy, game_assets_t *win)
{
    if (!enemy->enemy->is_touch && enemy->enemy->prev_touch)
        enemy->enemy->prev_touch = false;
    if (enemy->enemy->is_touch == false)
        return false;
    if (!enemy->enemy->prev_touch) {
        enemy->enemy->prev_touch = true;
        enemy->enemy->life -= enemy->enemy->life_to_rm;
        if (enemy->enemy->life <= 0) {
            add_items_wall(wall, win, enemy->pos1);
            play_song(win, SG_DEAD, enemy->pos1);
            remove_wall(wall, enemy);
            return true;
        }
        play_song(win, SG_TOUCH, enemy->pos1);
    }
    return false;
}
