/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** display_item.c
*/

#include "enemy.h"
#include "window_manage.h"
#include "map.h"
#include "player.h"
#include "items.h"
#include "texture_pack.h"

static void set_vertext(sfVertex vertex[4], game_assets_t *win,
    sfVector3f pr, wall_t *item)
{
    float z_add = pr.z * SIZE_ITEM / SIZE_WALL;
    sfVector3f pr2 = {pr.x + z_add / 2.0, pr.y, pr.z};
    float left = item->item->rect.left;
    float top = item->item->rect.top;
    float width = item->item->rect.width;
    float height = item->item->rect.height;

    pr.x -= z_add / 2.0;
    vertex[0] = (sfVertex){.position = add_to_vector(pr, z_add, win),
        .color = sfWhite, .texCoords = {left, top}};
    vertex[1] = (sfVertex){.position = add_to_vector(pr, 0.0, win),
        .color = sfWhite, .texCoords = {left, top + height}};
    vertex[2] = (sfVertex){.position = add_to_vector(pr2, 0.0, win),
        .color = sfWhite, .texCoords = {left + width, top + height}};
    vertex[3] = (sfVertex){.position = add_to_vector(pr2, z_add, win),
        .color = sfWhite, .texCoords = {left + width, top}};
}

static void draw(game_assets_t *win, wall_t *item)
{
    sfRenderStates st = {sfBlendAlpha, sfTransform_Identity,
        pack(item->item->texture, win->text_pack), NULL};

    sfVertexArray_setPrimitiveType(win->csfml.quad, sfQuads);
    sfRenderTexture_drawVertexArray(win->csfml.rend_text,
        win->csfml.quad, &st);
}

void display_item(game_assets_t *win, wall_t *item)
{
    sfVertex vertex[4] = {0};
    sfVector3f pt = {0};

    if (item == NULL)
        return;
    if (win->shadow_room && item->distance >= MAX_SHADOW)
        return;
    pt = project_pt(win, item->pos1, &item->printbale);
    if (item->printbale != PRINTABLE)
        return;
    sfVertexArray_clear(win->csfml.quad);
    set_vertext(vertex, win, pt, item);
    for (size_t i = 0; i < 4; ++i)
        sfVertexArray_append(win->csfml.quad, vertex[i]);
    draw(win, item);
}
