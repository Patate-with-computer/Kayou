/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** init_an_enemy.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "enemy.h"
#include "map.h"
#include "player.h"
#include "texture_pack.h"
#include "lib.h"

const enemy_attack_t enemy_attack_list[] = {
    {{0, 0, 0, 0}, {0, 0}, {0, 0}, 0.0, DIST_ATK(LONG) + 100,
        100.0, 0.0, 0.0, 10.0, 1000.0},
    {{0, 0, 0, 0}, {0, 0}, {0, 0}, 0.0, DIST_ATK(LONG) + 200,
        120.0, 0.0, 0.0, 30.0, 200.0},
    {{0, 0, 0, 0}, {0, 0}, {0, 0}, 0.0, DIST_ATK(LONG) + 200,
        130.0, 0.0, 0.0, 20.0, 100.0},
    {{0, 0, 0, 0}, {0, 0}, {0, 0}, 0.0, DIST_ATK(BOSS),
        300.0, 0.0, 0.0, 70.0, 10.0},
    {{0, 0, 0, 0}, {0, 0}, {0, 0}, 0.0, DIST_ATK(BOSS),
        130.0, 0.0, 0.0, 15.0, 500.0}
};

static void set_rect_and_size(wall_t *attack, texture_pack_t *text_pack)
{
    sfVector2u size = sfTexture_getSize(pack(attack->texture, text_pack));

    attack->enemy_attack->size = (sfVector2f){size.x, size.y};
    attack->enemy_attack->rect = (sfFloatRect){0.0, 0.0, size.y, size.y};
}

static float get_angle(wall_t *enemy, player_t *player)
{
    sfVector2f pos = {player->pos.x - enemy->pos1.x,
                        player->pos.y - enemy->pos1.y};

    return atan2(pos.y, pos.x);
}

void add_an_attack(wall_t *enemy, game_assets_t *win)
{
    sfVector2f pos_wall[3] = {enemy->pos1, {0.0, 0.0}, {0.0, 0.0}};
    wall_t *attack = init_a_wall(pos_wall);

    if (attack == NULL)
        return free_one_wall(attack);
    attack->enemy_attack = malloc(sizeof(enemy_attack_t));
    if (attack->enemy_attack == NULL)
        return free_one_wall(attack);
    (void)memcpy(attack->enemy_attack,
        &enemy_attack_list[enemy->texture.text_nb], sizeof(enemy_attack_t));
    attack->object = IS_ATTACK;
    attack->texture = (set_texture_t){ATTACK_TYPE, enemy->texture.text_nb};
    set_rect_and_size(attack, win->text_pack);
    attack->enemy_attack->init_pos = enemy->pos1;
    attack->enemy_attack->angle = get_angle(enemy, win->entities.player);
    attack->enemy_attack->anc_time_move = get_millis(win->csfml.clock);
    add_wall(&win->entities.wall, attack);
}
