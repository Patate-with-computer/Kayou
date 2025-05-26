/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** init_an_enemy.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "enemy.h"
#include "map.h"
#include "texture_pack.h"
#include "lib.h"

void add_an_enemy(size_t nb_en, sfVector2f pos,
    game_assets_t *win, float life)
{
    sfVector2f pos_wall[3] = {pos, {0.0, 0.0}, {0.0, 0.0}};
    wall_t *enemy = init_a_wall(pos_wall);

    if (enemy == NULL)
        return free_one_wall(enemy);
    enemy->enemy = malloc(sizeof(enemy_t));
    if (enemy->enemy == NULL)
        return free_one_wall(enemy);
    enemy->texture = (set_texture_t){ENEMY_TYPE, nb_en};
    enemy->enemy->anc_time = 0.0;
    enemy->enemy->anc_time_move = get_millis(win->csfml.clock);
    enemy->object = IS_ENEMY;
    enemy->enemy->angle = 0;
    enemy->enemy->wait_time =
        enemy_attack_list[nb_en].reload_time + randint(MAX_TIME_ADD_TO_WAIT);
    set_texture_and_var(enemy->enemy, life, win->text_pack, enemy->texture);
    add_wall(&win->entities.wall, enemy);
}
