/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** add_all_weapon.c
*/

#include "window_manage.h"
#include "file_manage.h"
#include "player.h"
#include "map.h"
#include "lib.h"
#include "texture_pack.h"

static const weapon_config_t config[NB_WEAPON] = {
    // atk_text   wp_text  price damage max_dist triangle  reload mana
    {WP_ROCK, WP_ROCK_VIEW, 0.0, 2.0, 300.0, 10.0, RELOAD(ROCK), 0},
    {WP_PISTOL, WP_PISTOL_VIEW, 50.0, 15.0, 500.0, 10.0, RELOAD(PISTOL), 2},
    {WP_BAG, WP_BAG_VIEW, 150.0, 16.0, 200.0, 10.0, RELOAD(BAG), 1},
    {WP_LIGHT, WP_LIGHT_VIEW, 500.0, 300.0, 150.0, 20.0, -1, 50.0}
};

void add_all_weapon(game_assets_t *win)
{
    player_t *player = win->entities.player;

    for (size_t i = 0; i < NB_WEAPON; ++i) {
        player->weapon[i] = init_weapon(config[i].nb_text,
            config[i].attack, win->text_pack);
        if (player->weapon[i] == NULL)
            continue;
        player->weapon[i]->weapon->init_max_dist = config[i].max_dist;
        player->weapon[i]->weapon->init_tr = config[i].init_tr;
        player->weapon[i]->weapon->reload_time = config[i].reload_time;
        player->weapon[i]->weapon->price = config[i].price;
        player->weapon[i]->weapon->text_purchase = config[i].nb_text_purchase;
        player->weapon[i]->weapon->mana_to_rm = config[i].mana;
        add_wall(&win->entities.wall, player->weapon[i]);
    }
}
