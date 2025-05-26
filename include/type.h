/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** type.h
*/

#ifndef WOLF_TYPE_H
    #define WOLF_TYPE_H

// type of textures
typedef enum pack_type_s {
    ENEMY_TYPE,
    ITEMS_TYPE,
    TARGET_TYPE,
    WALL_TYPE,
    WEAPON_TYPE,
    ATTACK_TYPE
} pack_type_t;

// struct to set the texture
typedef struct set_texture_s {
    pack_type_t type;
    size_t text_nb;
} set_texture_t;

#endif
