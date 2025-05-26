/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** free_player.c
*/

#include "lib.h"
#include "map.h"
#include "player.h"

void free_player(player_t *player)
{
    MY_FREE(player);
}
