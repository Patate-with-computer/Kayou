/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** init_weapon.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "enemy.h"
#include "player.h"
#include "file_manage.h"
#include "texture_pack.h"
#include "map.h"

static void set_weapon_info(wall_t *weapon, float attack,
    texture_pack_t *text_pack)
{
    sfVector2u size = {0};
    weapon_t *weap = weapon->weapon;

    weap->text_purchase = 0;
    weap->max_dist = MAX_DIST;
    weap->init_max_dist = MAX_DIST;
    size = sfTexture_getSize(pack(weapon->texture, text_pack));
    weap->size = (sfVector2f){(float)size.x, (float)size.y};
    weap->rect = (sfFloatRect){0.0, 0.0,
        weap->size.y / NB_TEXT_WEAPON, weap->size.y / NB_TEXT_WEAPON};
    weap->is_attacking = false;
    weapon->object = IS_WEAPON;
    weap->anc_time = 0.0;
    weap->attack = attack;
    weap->anc_reload_time = 0.0;
    weap->reload_time = -1.0;
}

wall_t *init_weapon(size_t nb_text, float attack, texture_pack_t *text_pack)
{
    sfVector2f pos_wall[3] = {{150.0, 40.0}, {0.0, 0.0}, {0.0, 0.0}};
    wall_t *wall = init_a_wall(pos_wall);

    if (wall == NULL) {
        free_wall(wall);
        return NULL;
    }
    wall->weapon = malloc(sizeof(weapon_t));
    if (wall->weapon == NULL) {
        free_wall(wall);
        return NULL;
    }
    wall->texture = (set_texture_t){WEAPON_TYPE, nb_text};
    set_weapon_info(wall, attack, text_pack);
    wall->weapon->tr_size = TRIANGLE_SIZE;
    wall->weapon->init_tr = TRIANGLE_SIZE;
    wall->weapon->mana_to_rm = 0.0;
    return wall;
}
