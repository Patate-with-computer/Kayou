/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** get_texture_pack_name.c
*/

#include <dirent.h>
#include <string.h>
#include "texture_pack.h"

char **get_texture_pack_name(void)
{
    DIR *dir = opendir(texture_pack_dir);
    size_t index = 0;
    static char *pack_name[MAX_TEXTURE_PACK + 1] = {0};

    for (size_t i = 0; i < MAX_TEXTURE_PACK + 1; ++i)
        pack_name[i] = NULL;
    if (dir == NULL)
        return pack_name;
    for (struct dirent *dir_struct = readdir(dir); dir_struct != NULL;
            dir_struct = readdir(dir)) {
        if (strcmp(dir_struct->d_name, ".") == 0 ||
            strcmp(dir_struct->d_name, "..") == 0)
            continue;
        if (index >= MAX_TEXTURE_PACK)
            break;
        pack_name[index] = strdup(dir_struct->d_name);
        ++index;
    }
    closedir(dir);
    return pack_name;
}
