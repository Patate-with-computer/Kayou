/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** is_file_exist.c
*/

#include <stdbool.h>
#include <unistd.h>

bool is_file_exist(const char *file_name)
{
    return access(file_name, F_OK) == 0;
}
