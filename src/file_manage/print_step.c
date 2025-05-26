/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** print_step.c
*/

#include <math.h>
#include "file_manage.h"
#include "player.h"
#include "map.h"

static void set_var(sfVector2f *current, sfVector2f end, sfVector2f dd)
{
    sfVector2f next = {0, 0};

    next.x = (*current).x + dd.x;
    next.y = (*current).y + dd.y;
    if ((dd.x > 0 && next.x > end.x) || (dd.x < 0 && next.x < end.x))
        next.x = end.x;
    if ((dd.y > 0 && next.y > end.y) || (dd.y < 0 && next.y < end.y))
        next.y = end.y;
    (*current).x = next.x;
    (*current).y = next.y;
}

void print_step(scan_line_t *scan, FILE *dest)
{
    sfVector2f current = {scan->start.x, scan->start.y};
    float first = get_distance(scan->start, scan->end);
    sfVector2f rect = {0.0, 0.0};

    while (get_distance(current, scan->start) <= first) {
        rect.x = rect.y;
        scan->to_write[0] = current;
        set_var(&current, scan->end, scan->dd);
        rect.y = fminf(rect.y + scan->step, SIZE_TEXT(PLAYER));
        scan->to_write[1] = current;
        scan->to_write[2] = rect;
        fwrite(scan->to_write, sizeof(sfVector2f), 3, dest);
        fwrite(&scan->hidden, sizeof(bool), 1, dest);
        if (rect.y == SIZE_TEXT(PLAYER))
            rect.y = 0;
        if (current.x == scan->end.x && current.y == scan->end.y)
            break;
    }
}
