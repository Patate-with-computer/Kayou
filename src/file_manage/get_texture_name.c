/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** get_texture_name.c
*/

#include <string.h>
#include <stdio.h>

char *get_texture_name(char const *file_name, const char *text_pack,
    const char *folder)
{
    static char text_name[BUFSIZ] = {0};

    memset(text_name, 0, BUFSIZ);
    sprintf(text_name, "assets/texture_pack/%s/%s/%s", text_pack, folder,
        file_name);
    return text_name;
}
