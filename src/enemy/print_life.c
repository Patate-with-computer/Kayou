/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** print_life.c
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "enemy.h"
#include "window/window_manage.h"
#include "map.h"
#include "player.h"
#include "texture_pack.h"


static void set_vertext(sfVertex vertex[4], sfVector2f pos,
    sfVector2f add, sfColor color)
{
    vertex[0] = (sfVertex){.position = {pos.x, pos.y},
        .color = color};
    vertex[1] = (sfVertex){.position = {pos.x + add.x, pos.y},
        .color = color};
    vertex[2] = (sfVertex){.position = {pos.x + add.x, pos.y + add.y},
        .color = color};
    vertex[3] = (sfVertex){.position = {pos.x, pos.y + add.y},
        .color = color};
}

static void draw(game_assets_t *win, sfVertex vertex[4])
{
    sfRenderStates st = {sfBlendAlpha, sfTransform_Identity,
        NULL, NULL};

    sfTransform_scale(&st.transform, win->scale.x, win->scale.y);
    sfVertexArray_clear(win->csfml.quad);
    for (size_t i = 0; i < 4; ++i)
        sfVertexArray_append(win->csfml.quad, vertex[i]);
    sfVertexArray_setPrimitiveType(win->csfml.quad, sfQuads);
    sfRenderTexture_drawVertexArray(win->csfml.rend_text,
        win->csfml.quad, &st);
}

void print_life_str(game_assets_t *win, wall_t *wall, sfVector3f pr)
{
    enemy_t *enemy = wall->enemy;
    float z_add = pr.z * SIZE_ENEMY / SIZE_WALL;
    sfVertex vertex[4] = {0};
    sfVector2f pos = add_to_vector(pr, z_add, win);
    float z_add2 = pr.z * SIZE_LIFE_BAR / SIZE_WALL;
    float to_rm = pr.z * SIZE_TO_REMOVE_LIFEBAR / SIZE_WALL;
    float p = enemy->life / enemy->max_life;
    sfColor color = {255 * (1 - p * p * p), 255 * p * p, 50, 255};

    pos.x /= win->scale.x;
    pos.y /= win->scale.y;
    pos.x += to_rm;
    z_add -= to_rm * 2.0;
    set_vertext(vertex, pos, (sfVector2f){z_add, -z_add2}, back_lifebar);
    draw(win, vertex);
    set_vertext(vertex, pos, (sfVector2f){z_add * p, -z_add2}, color);
    draw(win, vertex);
}
