/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** set_all_null.c
*/

#include "lib.h"

void set_all_null(void *struct_to_null, type_to_set_t type)
{
    void (*null_function[])(void *ptr) = {set_song_lib_to_null,
        null_game_assets_struct, null_texture_pack_struct,
        null_player_struct, set_all_null_menu, null_echap_menu};

    null_function[type](struct_to_null);
}
