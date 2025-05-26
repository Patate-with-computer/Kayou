/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** convert_file.c
*/

#include "file_manage.h"

void convert_file(const char *file_name, float step)
{
    FILE *fd = fopen(file_name, "r");
    FILE *fdest = NULL;
    char dest[BUFSIZ] = {0};

    if (fd == NULL)
        return;
    get_file_write_name(file_name, dest, WOLF_TERM);
    fdest = fopen(dest, "wb");
    if (fdest == NULL)
        return (void)fclose(fd);
    scan_all_line(fd, fdest, step);
    (void)fclose(fdest);
    (void)fclose(fd);
}
