/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** convert_enemy.c
*/

#include <string.h>
#include "file_manage.h"
#include "lib.h"

static sfBool check_line(char *buff, int len)
{
    if (buff == NULL || buff[0] == COMMENT_CHAR || buff[0] == '\n')
        return sfTrue;
    if (buff[len - 1] == '\n')
        buff[len - 1] = '\0';
    return sfFalse;
}

static void scan_enemy_line(FILE *src, FILE *dest)
{
    char *buff = NULL;
    size_t size = 0;
    sfVector2f pos = {0.0, 0.0};
    char file_name[BUFSIZ] = {0};
    float life = 0.0;

    for (int len = 0; len != -1; len = getline(&buff, &size, src)) {
        if (check_line(buff, len))
            continue;
        memset(file_name, 0, sizeof(char) * BUFSIZ);
        if (sscanf(buff, SCAN_ENEMY, &pos.x, &pos.y,
                    &life, file_name) == NBR_ELEMENT_ENEMY) {
            printf("%s - %.2f:%.2f life: %.2f\n", file_name,
                pos.x, pos.y, life);
            fwrite(file_name, sizeof(char), BUFSIZ, dest);
            fwrite(&pos, sizeof(sfVector2f), 1, dest);
            fwrite(&life, sizeof(float), 1, dest);
        }
    }
    MY_FREE(buff);
}

void convert_enemy(const char *file_name)
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
    scan_enemy_line(fd, fdest);
    (void)fclose(fdest);
    (void)fclose(fd);
}
