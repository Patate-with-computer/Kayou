/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** init_texture_pack.c
*/

#include <stdlib.h>
#include "texture_pack.h"
#include "lib.h"

static void init_all_pack(texture_pack_t *text_pack, const char *pack_name)
{
    text_pack->enemy_text = init_one_pack(GET_ARRAY(enemy),
        GET_FOLDER(enemy), pack_name);
    text_pack->items_text = init_one_pack(GET_ARRAY(items),
        GET_FOLDER(items), pack_name);
    text_pack->target_text = init_one_pack(GET_ARRAY(target),
        GET_FOLDER(target), pack_name);
    text_pack->weapon_text = init_one_pack(GET_ARRAY(weapon),
        GET_FOLDER(weapon), pack_name);
    text_pack->wall_text = init_one_pack(GET_ARRAY(wall),
        GET_FOLDER(wall), pack_name);
    text_pack->attack_text = init_one_pack(GET_ARRAY(attack),
        GET_FOLDER(attack), pack_name);
}

texture_pack_t *init_texture_pack(const char *pack_name)
{
    texture_pack_t *text_pack = malloc(sizeof(texture_pack_t));

    if (text_pack == NULL)
        return NULL;
    set_all_null(text_pack, TEXTPACK_LIB_TYPE);
    init_all_pack(text_pack, pack_name);
    if (text_pack->enemy_text == NULL || text_pack->items_text == NULL ||
        text_pack->target_text == NULL || text_pack->weapon_text == NULL ||
        text_pack->wall_text == NULL || text_pack->attack_text == NULL)
        return free_texture_pack(text_pack);
    return text_pack;
}
