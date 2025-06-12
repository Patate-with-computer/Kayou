/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** sort_wall.c
*/

#include <stdlib.h>
#include "map.h"

int count_walls_limit(wall_t *head, float limit)
{
    int count = 0;

    for (; head != NULL; head = head->next)
        if (head->distance < limit)
            count++;
    return count;
}

static int compare_walls(const void *a, const void *b)
{
    wall_t *wa = *(wall_t **)a;
    wall_t *wb = *(wall_t **)b;

    return (wa->distance > wb->distance) - (wa->distance < wb->distance);
}

static void set_array(wall_t **head, wall_t **array, wall_t **last_unsorted)
{
    wall_t *curr = *head;
    wall_t *next = NULL;
    int i = 0;

    while (curr != NULL) {
        next = curr->next;
        if (curr->distance < MAX_DIST_RENDER) {
            array[i] = curr;
            ++i;
        } else {
            *last_unsorted = curr;
            last_unsorted = &curr->next;
        }
        curr = next;
    }
    *last_unsorted = NULL;
}

void sort_wall(wall_t **head)
{
    int count = count_walls_limit(*head, MAX_DIST_RENDER);
    wall_t **array = NULL;
    wall_t *unsorted_part = NULL;
    wall_t **last_unsorted = &unsorted_part;

    if (count <= 1)
        return;
    array = malloc(sizeof(wall_t *) * count);
    if (array == NULL)
        return;
    set_array(head, array, last_unsorted);
    qsort(array, count, sizeof(wall_t *), compare_walls);
    for (int i = 0; i < count - 1; i++)
        array[i]->next = array[i + 1];
    array[count - 1]->next = unsorted_part;
    *head = array[0];
    free(array);
}
