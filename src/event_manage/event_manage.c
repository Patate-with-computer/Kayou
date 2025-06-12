/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** event_manage.c
*/

#include "window/window_manage.h"
#include "player.h"
#include "event_manage.h"
#include "enemy.h"
#include "map.h"
#include "lib.h"
#include "save_manage.h"

sfBool get_key_attack(void)
{
    return sfKeyboard_isKeyPressed(sfKeySpace) ||
        sfMouse_isButtonPressed(sfMouseLeft) ||
        get_joy_button(0, BUTTON_R1);
}

sfBool get_confirm_key(void)
{
    if (sfJoystick_isConnected(0))
        return get_joy_button(0, BUTTON_CIRCLE);
    else
        return sfMouse_isButtonPressed(sfMouseLeft);
}

void space_event(game_assets_t *window)
{
    static int prev_state = 0;
    sfBool key_p = get_key_attack();
    player_t *pl = window->entities.player;
    wall_t *weapon = pl->weapon[pl->weapon_name];
    float reload = 0.0;

    if (weapon == NULL || window->is_paused)
        return;
    reload = weapon->weapon->reload_time;
    if (key_p && !prev_state) {
        weapon->weapon->is_attacking = true;
        prev_state = 1;
        weapon->weapon->anc_reload_time = get_millis(window->csfml.clock);
    }
    if ((reload != -1 && get_millis(window->csfml.clock) -
        weapon->weapon->anc_reload_time >= reload) || (!key_p && prev_state))
        prev_state = 0;
}

static void set_all_attack(player_t *pl)
{
    for (size_t i = 0; i < NB_WEAPON; i++) {
        if (pl->weapon[i] == NULL)
            continue;
        pl->weapon[i]->weapon->is_attacking = false;
    }
}

static void set_next_weapon(player_t *pl)
{
    weapon_name_t next = (pl->weapon_name + 1) % NB_WEAPON;

    for (; pl->get_weapon[next % NB_WEAPON] == false; ++next);
    pl->weapon_name = next % NB_WEAPON;
}

static void r_event(player_t *pl)
{
    static bool prev_state = false;
    sfBool key_e = sfFalse;

    if (!check_weapon_exist(pl))
        return;
    key_e = sfKeyboard_isKeyPressed(sfKeyR) ||
        get_joy_button(0, BUTTON_L1);
    if (!prev_state && key_e) {
        set_all_attack(pl);
        set_next_weapon(pl);
        prev_state = true;
    }
    if (prev_state && !key_e)
        prev_state = false;
}

static void set_pause(game_assets_t *win)
{
    if (get_one_e()) {
        if (!win->is_paused) {
            win->is_paused = true;
            win->is_echap_menu = false;
            return;
        }
        if (win->is_paused && !win->is_echap_menu)
            win->is_paused = false;
    }
    if (get_one_escape()) {
        if (win->is_echap_menu && win->is_paused) {
            win->is_echap_menu = false;
            win->is_paused = false;
            return;
        }
        win->is_echap_menu = true;
        if (!win->is_paused)
            win->is_paused = true;
    }
}

static void manage_maze_menu(game_assets_t *win)
{
    if (win->win_type == MAZE) {
        move_player(win);
        space_event(win);
        r_event(win->entities.player);
        set_all_texture(win);
        set_pause(win);
    }
}

void event_manage(game_assets_t *win)
{
    get_win_scale(win);
    while (sfRenderWindow_pollEvent(win->csfml.win, &win->event)) {
        if (win->event.type == sfEvtClosed || win->win_type == EXIT_MENU) {
            sfRenderWindow_close(win->csfml.win);
        }
        if (win->event.type == sfEvtJoystickButtonPressed &&
            win->win_type == CREDITS_MENU)
            win->win_type = MAIN_MENU;
    }
    manage_maze_menu(win);
    if (win->win_type == CREDITS_MENU) {
        if (win->event.type == sfEvtKeyPressed)
            win->win_type = MAIN_MENU;
    }
}
