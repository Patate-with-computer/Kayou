/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** read_file.c
*/

#include <stdlib.h>
#include <string.h>
#include "enemy.h"
#include "file_manage.h"
#include "map.h"
#include "texture_pack.h"

static size_t read_info(char read_file_name[BUFSIZ], sfVector2f *read_pos,
    float *life, FILE *fd)
{
    size_t len = 0;

    len = fread(read_file_name, sizeof(char), BUFSIZ, fd);
    if (len == 0)
        return len;
    len = fread(read_pos, sizeof(sfVector2f), 1, fd);
    if (len == 0)
        return len;
    len = fread(life, sizeof(float), 1, fd);
    if (len == 0)
        return len;
    return len;
}

static size_t get_nb_enemy(const char name[BUFSIZ])
{
    for (size_t i = 0; GET_ARRAY(enemy)[i] != NULL; ++i) {
        if (strcmp(name, GET_ARRAY(enemy)[i]) != 0)
            continue;
        return i;
    }
    return 0;
}

void read_file_enemy(const char *file_name, game_assets_t *win)
{
    FILE *fd = fopen(file_name, "rb");
    sfVector2f read_pos = {0.0, 0.0};
    char read_file_name[BUFSIZ] = {0};
    float life = 0.0;
    size_t len = 0;

    if (fd == NULL)
        return;
    do {
        len = read_info(read_file_name, &read_pos, &life, fd);
        if (len == 0)
            break;
        add_an_enemy(get_nb_enemy(read_file_name), read_pos, win, life);
    } while (len != 0);
    (void)fclose(fd);
}
