/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** create_rectangle.c
*/

#include <math.h>
#include "file_manage.h"
#include "player.h"

void create_rectangle(scan_line_t *scan, FILE *dest)
{
    scan->start1 = scan->start;
    scan->end1 = scan->end;
    print_step(scan, dest);
    scan->start = (sfVector2f){scan->start.x - sinf(scan->a) * WALL_THICKNESS,
        scan->start.y + cosf(scan->a) * WALL_THICKNESS};
    scan->end = (sfVector2f){scan->end.x - sinf(scan->a) * WALL_THICKNESS,
        scan->end.y + cosf(scan->a) * WALL_THICKNESS};
    scan->start2 = scan->start;
    scan->end2 = scan->end;
    print_step(scan, dest);
    scan->dd = (sfVector2f){cosf(scan->a - X_AXCIS) * scan->step,
        sinf(scan->a + X_AXCIS) * scan->step};
    scan->start = scan->end1;
    scan->end = scan->end2;
    print_step(scan, dest);
    scan->start = scan->start1;
    scan->end = scan->start2;
    print_step(scan, dest);
}
