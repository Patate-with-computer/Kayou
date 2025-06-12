/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** get_cutstr.c
*/

#include <stdio.h>
#include <string.h>

char *get_cutstr(const char *src, size_t size_to_cpy)
{
    static char tmp[BUFSIZ] = {0};
    size_t max_len = strlen(src);
    size_t max = size_to_cpy;
    size_t index = 0;

    memset(tmp, 0, BUFSIZ * sizeof(char));
    if (size_to_cpy > max_len)
        max = max_len;
    for (size_t i = 0; i < max; ++i) {
        if (src[i] == '\n')
            continue;
        tmp[index] = src[i];
        ++index;
    }
    if (max > 0 && src[max] != ' ' && src[max - 1] != ' ' &&
        src[max] != '\n' && src[max] != '\0')
        strcat(tmp, "-");
    return tmp;
}
