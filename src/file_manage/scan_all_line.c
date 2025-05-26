/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** scan_all_line.c
*/

#include <math.h>
#include <string.h>
#include "file_manage.h"
#include "lib.h"
#include "map.h"
#include "player.h"
#include "texture_pack.h"

static void scan_line(const char *line, FILE *dest, float step)
{
    scan_line_t scan = {0};
    char hidden = '\0';
    int sc = sscanf(line, SCAN_LINE, &scan.start.x, &scan.start.y,
        &scan.end.x, &scan.end.y, &hidden);

    scan.step = step;
    memset(scan.to_write, 0, sizeof(sfVector2f) * 3);
    scan.hidden = (sc == NBR_ELEMENT + 1);
    if (sc == NBR_ELEMENT || sc == NBR_ELEMENT + 1) {
        if (scan.hidden)
            printf("SECRET - ");
        printf("%s\n", line);
        scan.a = atan2f(scan.end.y - scan.start.y, scan.end.x - scan.start.x);
        scan.dd = (sfVector2f){cosf(scan.a) * scan.step,
            sinf(scan.a) * scan.step};
        create_rectangle(&scan, dest);
    }
}

static size_t get_nb_wall(char *buff, FILE *src)
{
    char name[BUFSIZ] = {0};
    size_t size = 0;

    getline(&buff, &size, src);
    sscanf(buff, SCAN_TEXTURE, name);
    for (size_t i = 0; GET_ARRAY(wall)[i] != NULL; ++i) {
        if (strcmp(name, GET_ARRAY(wall)[i]) != 0)
            continue;
        return i;
    }
    return 0;
}

void scan_all_line(FILE *src, FILE *dest, float step)
{
    char *buff = NULL;
    size_t size = 0;
    sfVector2f pos = {0.0, 0.0};
    size_t nb_text = 0;

    getline(&buff, &size, src);
    sscanf(buff, SCAN_POS, &pos.x, &pos.y);
    fwrite(&pos, sizeof(sfVector2f), 1, dest);
    nb_text = get_nb_wall(buff, src);
    fwrite(&nb_text, sizeof(size_t), 1, dest);
    for (int len = 0; len != -1; len = getline(&buff, &size, src)) {
        if (buff == NULL || buff[0] == COMMENT_CHAR || buff[0] == '\n')
            continue;
        if (buff[len - 1] == '\n')
            buff[len - 1] = '\0';
        scan_line(buff, dest, step);
    }
    MY_FREE(buff);
}
