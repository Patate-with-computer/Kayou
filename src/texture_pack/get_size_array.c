/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** get_size_array.c
*/

#include <stdio.h>

size_t get_size_array(const char *array[])
{
    size_t i = 0;

    for (; array[i] != NULL; ++i);
    return i;
}
