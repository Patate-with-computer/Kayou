/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** get_file_write_name.c
*/

#include <string.h>
#include "file_manage.h"

void get_file_write_name(const char *src, char dest[BUFSIZ], const char *term)
{
    size_t i = 0;

    memset(dest, 0, BUFSIZ);
    for (; src[i] != '.' && src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    strcat(dest, term);
}
