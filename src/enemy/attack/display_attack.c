/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** display_enemy.c
*/

#include <stdio.h>
#include "enemy.h"
#include "window/window_manage.h"
#include "map.h"
#include "player.h"
#include "texture_pack.h"

static void set_vertext(sfVertex vertex[4], game_assets_t *win,
    sfVector3f pr, wall_t *attck)
{
    float z_add = pr.z * SIZE_ENEMY_ATK / SIZE_WALL;
    sfVector3f pr2 = pr;
    float left = attck->enemy_attack->rect.left;
    float top = attck->enemy_attack->rect.top;
    float width = attck->enemy_attack->rect.width;
    float height = attck->enemy_attack->rect.height;

    pr.x -= z_add / 2.0;
    pr2.x += z_add / 2.0;
    vertex[0] = (sfVertex){.position = add_to_vector(pr, z_add, win),
        .color = sfWhite, .texCoords = {left, top}};
    vertex[1] = (sfVertex){.position = add_to_vector(pr, 0.0, win),
        .color = sfWhite, .texCoords = {left, top + height}};
    vertex[2] = (sfVertex){.position = add_to_vector(pr2, 0.0, win),
        .color = sfWhite, .texCoords = {left + width, top + height}};
    vertex[3] = (sfVertex){.position = add_to_vector(pr2, z_add, win),
        .color = sfWhite, .texCoords = {left + width, top}};
}

static void draw(game_assets_t *win, wall_t *attack)
{
    sfRenderStates st = {sfBlendAlpha, sfTransform_Identity,
        pack(attack->texture, win->text_pack), NULL};

    sfVertexArray_setPrimitiveType(win->csfml.quad, sfQuads);
    sfRenderTexture_drawVertexArray(win->csfml.rend_text,
        win->csfml.quad, &st);
}

void display_attack(game_assets_t *win, wall_t *attack)
{
    sfVertex vertex[4] = {0};
    sfVector3f pt = {0};

    if (attack == NULL)
        return;
    pt = project_pt(win, attack->pos1, &attack->printbale);
    if (attack->printbale != PRINTABLE)
        return;
    sfVertexArray_clear(win->csfml.quad);
    set_vertext(vertex, win, pt, attack);
    for (size_t i = 0; i < 4; ++i)
        sfVertexArray_append(win->csfml.quad, vertex[i]);
    draw(win, attack);
}
