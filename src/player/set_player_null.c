/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** set_player_null.c
*/

#include <stddef.h>
#include "player.h"

void null_player_struct(void *to_null)
{
    player_t *player = (player_t *)to_null;

    player->wall_to_break = NULL;
    for (size_t i = 0; i < NB_WEAPON; ++i) {
        player->get_weapon[i] = false;
        player->weapon[i] = NULL;
    }
}
