/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** get_filename.c
*/

#include <string.h>
#include <stdio.h>
#include "save_manage.h"
#include "file_manage.h"

char *get_filename(size_t nb_save)
{
    static char file_name[BUFSIZ] = {0};

    memset(file_name, 0, sizeof(char) * BUFSIZ);
    sprintf(file_name, save_file_mode, save_folder, nb_save, WOLF_TERM);
    return file_name;
}
