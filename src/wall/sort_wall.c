/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** sort_wall.c
*/

#include <stddef.h>
#include "map.h"

static void sort_one_value(wall_t **tmp, wall_t *current, wall_t *sorted)
{
    (*tmp) = sorted;
    while ((*tmp)->next != NULL &&
            (*tmp)->next->distance < current->distance) {
        (*tmp) = (*tmp)->next;
    }
    current->next = (*tmp)->next;
    (*tmp)->next = current;
}

void sort_wall(wall_t **head)
{
    wall_t *sorted = NULL;
    wall_t *current = *head;
    wall_t *next = NULL;
    wall_t *tmp = NULL;

    while (current != NULL) {
        next = current->next;
        if (sorted == NULL || current->distance < sorted->distance) {
            current->next = sorted;
            sorted = current;
        } else
            sort_one_value(&tmp, current, sorted);
        current = next;
    }
    *head = sorted;
}
