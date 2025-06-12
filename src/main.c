/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <bits/getopt_core.h>
#include "window/window_manage.h"
#include "lib.h"
#include "file_manage.h"
#include "enemy.h"
#include "ground_evt.h"

static bool is_argument(int ac, char **av, win_type_t *type)
{
    float step = 20.0;
    char opt = '\0';

    opt = getopt(ac, av, "en:c:");
    if (opt == 'n') {
        convert_enemy(optarg);
        return true;
    }
    if (opt == 'c') {
        if (av[optind] != NULL)
            step = atof(av[optind]);
        if (step == 0.0)
            step = 20.0;
        convert_file(optarg, step);
        return true;
    }
    if (opt == 'e')
        *type = EDIT;
    return false;
}

static sfBool init_game(game_assets_t **to_init, win_type_t type)
{
    game_assets_t *win = init_window();

    if (win == NULL)
        return sfFalse;
    win->win_type = type;
    *to_init = win;
    return sfTrue;
}

static void get_god_mode(game_assets_t *win, char **av, int ac)
{
    win->is_god_mode = false;
    if (ac == 2 && strcmp(av[1], "godmode") == 0) {
        printf("You entered in godmode, good luck to die.\n");
        win->is_god_mode = true;
    }
    if (ac == 2 && strcmp(av[1], "demo") == 0) {
        printf("This is a demo of our game, enjoy !!\n");
        win->room = RM_DEMO;
    }
}

int main(int ac, char **av)
{
    game_assets_t *win = NULL;
    win_type_t type = MAIN_MENU;

    if (getenv("DISPLAY") == NULL)
        exit(84);
    srand(time(NULL));
    if (av[1] != NULL && is_argument(ac, av, &type))
        return 0;
    if (init_game(&win, type) == sfFalse)
        return 0;
    get_god_mode(win, av, ac);
    while (sfRenderWindow_isOpen(win->csfml.win))
        window_loop(win);
    (void)free_window(win);
    return 0;
}
