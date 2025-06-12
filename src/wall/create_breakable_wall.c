/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** create_breakable_wall.c
*/

#include <math.h>
#include "map.h"
#include "window/window_manage.h"
#include "player.h"
#include "texture_pack.h"

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

static void add_the_wall(sfVector2f wall_init[3],
    wall_t **anc_wall, size_t nb_text)
{
    wall_t *new_wall = init_a_wall(wall_init);

    if (new_wall == NULL)
        return;
    new_wall->texture.text_nb = nb_text;
    new_wall->is_breakable = true;
    add_wall(anc_wall, new_wall);
}

static sfVector2f get_dd(sfVector2f start, sfVector2f end)
{
    float angle = atan2f(end.y - start.y, end.x - start.x);

    return (sfVector2f){cosf(angle) * BK_STEP, sinf(angle) * BK_STEP};
}

void create_breakable_wall(game_assets_t *win, sfVector2f start,
    sfVector2f end, size_t nb_text)
{
    sfVector2f current = {start.x, start.y};
    float first = get_distance(start, end);
    sfVector2f rect = {0.0, 0.0};
    sfVector2f wall_init[3] = {{0, 0}, {0, 0}, {0, 0}};
    sfVector2f dd = get_dd(start, end);

    while (get_distance(current, start) <= first) {
        rect.x = rect.y;
        wall_init[0] = current;
        set_var(&current, end, dd);
        rect.y = fminf(rect.y + BK_STEP, SIZE_TEXT(PLAYER));
        wall_init[1] = current;
        wall_init[2] = rect;
        add_the_wall(wall_init, &win->entities.wall, nb_text);
        if (rect.y == SIZE_TEXT(PLAYER))
            rect.y = 0;
        if (current.x == end.x && current.y == end.y)
            break;
    }
}
