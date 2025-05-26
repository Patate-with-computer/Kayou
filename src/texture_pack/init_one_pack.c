/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** init_one_pack.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "texture_pack.h"
#include "file_manage.h"

static sfTexture *get_one_texture(const char *folder, const char *pack_name,
    const char *file_name)
{
    char *file = get_texture_name(file_name, pack_name, folder);
    sfTexture *text = sfTexture_createFromFile(file, NULL);

    if (text != NULL)
        return text;
    file = get_texture_name(file_name, default_pack, folder);
    return sfTexture_createFromFile(file, NULL);
}

sfTexture **init_one_pack(const char *text_array[],
    const char *folder, const char *pack_name)
{
    sfTexture **array = NULL;
    bool error = false;
    size_t size = get_size_array(text_array);

    array = malloc(sizeof(sfTexture *) * (size + 1));
    if (array == NULL)
        return NULL;
    for (size_t i = 0; i < size + 1; i++)
        array[i] = NULL;
    for (size_t i = 0; i < size; ++i) {
        array[i] = get_one_texture(folder, pack_name, text_array[i]);
        if (array[i] == NULL) {
            error = true;
            break;
        }
    }
    if (error)
        return free_one_pack(array);
    return array;
}
