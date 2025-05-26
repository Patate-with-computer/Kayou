/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** check_weapon.c
*/

#include "player.h"

sfBool check_weapon_exist(player_t *player)
{
    for (size_t i = 0; i < NB_WEAPON; ++i) {
        if (player->weapon[i] == NULL)
            continue;
        return sfTrue;
    }
    return sfFalse;
}
