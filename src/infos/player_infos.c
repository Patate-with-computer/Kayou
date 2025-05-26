/*
** EPITECH PROJECT, 2025
** Wolf3d
** File description:
** player_infos.c
*/

#include "map.h"
#include "player.h"
#include "texture_pack.h"
#include "window_manage.h"

void print_ath(game_assets_t *win)
{
    float to_add = 0;
    size_t nb_weapon = win->entities.player->weapon_name;
    weapon_t *weapon = win->entities.player->weapon[nb_weapon]->weapon;
    set_texture_t set = {WEAPON_TYPE, weapon->text_purchase};
    sfTexture *wp_text = pack(set, win->text_pack);

    if (win->is_echap_menu)
        return;
    to_add = print_one_text(win->entities.player->life, "Life",
        (sfVector2f){TO_ADD_ATH, -TO_ADD_ATH}, win);
    to_add = print_one_text(win->entities.player->money, "Money",
        (sfVector2f){to_add + TO_ADD_ATH, -TO_ADD_ATH}, win);
    to_add = print_one_text(win->entities.player->magic, "Mana",
        (sfVector2f){to_add + TO_ADD_ATH, -TO_ADD_ATH}, win);
    to_add = print_one_texture(wp_text,
        (sfVector2f){to_add + TO_ADD_ATH, TO_ADD_ATH}, win);
}
