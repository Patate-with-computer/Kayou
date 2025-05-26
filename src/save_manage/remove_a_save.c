/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** remove_a_save.c
*/

#include "save_manage.h"

void remove_a_save(size_t nb_save)
{
    (void)remove(get_filename(nb_save));
}
