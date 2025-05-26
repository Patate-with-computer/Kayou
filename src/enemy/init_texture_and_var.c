/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** init_texture_and_var.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "enemy.h"
#include "map.h"
#include "texture_pack.h"

static void init_var(enemy_t *enemy, float life)
{
    enemy->is_touch = false;
    enemy->prev_touch = false;
    enemy->life = life;
    enemy->max_life = life;
    enemy->life_to_rm = 0.0;
    enemy->anc_text_time = 0.0;
}

void set_texture_and_var(enemy_t *enemy, float life,
    texture_pack_t *text_pack, set_texture_t text)
{
    sfVector2u size = {0, 0};

    init_var(enemy, life);
    size = sfTexture_getSize(pack(text, text_pack));
    enemy->size = (sfVector2f){(float)size.x, (float)size.y};
    enemy->rect = (sfFloatRect){0.0, 0.0,
        size.y / NB_TEXT, size.y / NB_TEXT};
}
