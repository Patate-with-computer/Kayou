/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** read_file.c
*/

#include <stdlib.h>
#include "file_manage.h"
#include "map.h"
#include "player.h"
#include "wolf/type.h"
#include "texture_pack.h"

void add_wall(wall_t **anc_wal, wall_t *new_wall)
{
    if (new_wall == NULL)
        return;
    if (*anc_wal == NULL) {
        *anc_wal = new_wall;
        return;
    }
    new_wall->next = *anc_wal;
    (*anc_wal) = new_wall;
}

static void add_wall_and_text_nb(wall_t **wall,
    sfVector2f read_vec[3], size_t nb_text, bool hidden)
{
    wall_t *new_wall = init_a_wall(read_vec);

    if (new_wall == NULL)
        return;
    new_wall->texture.text_nb = nb_text;
    new_wall->hidden = hidden;
    add_wall(wall, new_wall);
}

wall_t *read_file(const char *file_name, sfVector2f *pos)
{
    FILE *fd = fopen(file_name, "rb");
    wall_t *wall = NULL;
    sfVector2f read_vec[3] = {0};
    bool hidden = false;
    size_t len = 0;
    size_t nb_text = 0;

    if (fd == NULL)
        return NULL;
    fread(pos, sizeof(sfVector2f), 1, fd);
    fread(&nb_text, sizeof(size_t), 1, fd);
    do {
        len = fread(read_vec, sizeof(sfVector2f), 3, fd);
        if (len == 0)
            break;
        fread(&hidden, sizeof(bool), 1, fd);
        add_wall_and_text_nb(&wall, read_vec, nb_text, hidden);
    } while (len != 0);
    (void)fclose(fd);
    return wall;
}
