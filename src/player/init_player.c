/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** init_player.c
*/

#include <stdlib.h>
#include <math.h>
#include "enemy.h"
#include "player.h"
#include "map.h"
#include "lib.h"

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (player == NULL)
        return NULL;
    set_all_null(player, PLAYER_LIB_TYPE);
    player->pos = (sfVector2f){0.0, 0.0};
    player->angle = (float)ANGLE;
    player->focal = 0.0;
    player->arrondie = 0.0;
    player->speed = INIT_SPEED;
    player->life = 100.0;
    player->anc_time = 0.0;
    player->weapon_name = PISTOL_WP;
    player->get_weapon[PISTOL_WP] = true;
    player->money = 0;
    player->magic = 50.0;
    return player;
}
