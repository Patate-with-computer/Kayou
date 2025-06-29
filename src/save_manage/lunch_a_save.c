/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** lunch_a_save.c
*/

#include <string.h>
#include <unistd.h>
#include "save_manage.h"
#include "window/window_manage.h"
#include "player.h"
#include "ground_evt.h"
#include "song_manage.h"
#include "screen_text.h"
#include "lib.h"

static void set_values(game_assets_t *win, player_t *pl, save_manage_t *save)
{
    if (save->player_life >= DEFAULT_LIFE)
        pl->life = save->player_life;
    else
        pl->life = DEFAULT_LIFE;
    pl->money = save->money;
    pl->magic = save->magic;
    pl->weapon_name = save->nb_weapon;
    win->timer = save->timer;
}

static void set_save_value(game_assets_t *win, save_manage_t *save,
    bool reset_pos)
{
    void (*init_level[])(game_assets_t *, sfVector2f) = {
        set_intro, set_hallway, set_hallway1, set_hallway2,
        set_secret, set_diag_map, set_labyrinth, set_hell_room,
        set_boss, set_corrupted_room, set_demo};
    player_t *pl = win->entities.player;

    set_values(win, pl, save);
    memcpy(pl->get_weapon, save->get_weapon, NB_WEAPON * sizeof(bool));
    if (win->room != RM_DEMO)
        win->room = save->actual_room;
    init_level[win->room](win, (sfVector2f){RESET, RESET});
    win->actual_demo = FIRST_ENEMY;
    if (reset_pos)
        pl->pos = save->player_pos;
}

static void init_save(game_assets_t *win, size_t nb_save)
{
    char *file_name = get_filename(nb_save);
    FILE *fd = NULL;
    save_manage_t save = default_save;
    bool reset_pos = false;

    if (is_file_exist(file_name)) {
        fd = fopen(file_name, "rb");
        if (fd == NULL)
            return;
        fread(&save, sizeof(save_manage_t), 1, fd);
        reset_pos = true;
        (void)fclose(fd);
    } else {
        win->put.txt = (char *)intro_txt;
        win->put.mode = BIG_MODE;
        win->put.current = TALK;
    }
    win->actual_boss = ATTACK;
    set_save_value(win, &save, reset_pos);
}

void lunch_a_save(game_assets_t *win, size_t nb_save)
{
    player_t *pl = win->entities.player;
    player_t *tmp = NULL;

    win->is_echap_menu = false;
    win->is_paused = false;
    win->timer = 0.0f;
    if (pl == NULL) {
        tmp = init_player();
        if (tmp != NULL) {
            free_player(win->entities.player);
            win->entities.player = tmp;
        }
    }
    sfMusic_setLoop(win->song_lib->music, sfTrue);
    sfMusic_play(win->song_lib->music);
    init_save(win, nb_save);
    sfSleep((sfTime){180000});
}
