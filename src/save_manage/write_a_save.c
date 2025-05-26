/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** write_a_save.c
*/

#include <string.h>
#include "player.h"
#include "save_manage.h"
#include "window_manage.h"
#include "file_manage.h"

void write_a_save(game_assets_t *assets, size_t nb_save)
{
    save_manage_t save = {0};
    player_t *pl = assets->entities.player;
    FILE *fd = NULL;

    if (pl == NULL || assets->win_type != MAZE)
        return;
    fd = fopen(get_filename(nb_save), "wb");
    if (fd == NULL)
        return;
    save.actual_room = assets->room;
    save.magic = pl->magic;
    save.money = pl->money;
    save.player_pos = pl->pos;
    save.player_life = pl->life;
    save.nb_weapon = pl->weapon_name;
    memcpy(save.get_weapon, pl->get_weapon, NB_WEAPON * sizeof(bool));
    (void)fwrite(&save, sizeof(save_manage_t), 1, fd);
    (void)fclose(fd);
}
