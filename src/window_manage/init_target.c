/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** init_target.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "target.h"
#include "file_manage.h"
#include "texture_pack.h"

target_t *free_target(target_t *target)
{
    if (target == NULL)
        return NULL;
    if (target->sprite != NULL)
        sfSprite_destroy(target->sprite);
    free(target);
    return NULL;
}

target_t *init_target(pack_type_t type, size_t nb, texture_pack_t *text_pack)
{
    target_t *target = malloc(sizeof(target_t));
    sfVector2f middle = {0.0, 0.0};
    sfTexture *texture = pack((set_texture_t){type, nb}, text_pack);

    if (target == NULL)
        return NULL;
    target->sprite = sfSprite_create();
    if (target->sprite == NULL)
        return free_target(target);
    target->size_x = (float)sfTexture_getSize(texture).x;
    middle.x = target->size_x / 2.0;
    middle.y = target->size_x / 2.0;
    sfSprite_setTexture(target->sprite, texture, sfTrue);
    sfSprite_setOrigin(target->sprite, middle);
    target->print_target = true;
    return target;
}
