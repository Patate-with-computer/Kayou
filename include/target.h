/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** target.h
*/

#ifndef TARGET_H
    #define TARGET_H
    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #define SIZE_PRINT 50.0
    #define SCALE(a) (SIZE_PRINT / a)
    #include "wolf/type.h"

typedef struct texture_pack_s texture_pack_t;

typedef struct target_s {
    sfSprite *sprite;
    float pos_y;
    float size_x;
    bool print_target;
} target_t;

target_t *free_target(target_t *target);
target_t *init_target(pack_type_t type, size_t nb, texture_pack_t *text_pack);

#endif
