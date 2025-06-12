/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** display_weapon.c
*/

#include "enemy.h"
#include "window/window_manage.h"
#include "map.h"
#include "player.h"
#include "texture_pack.h"

static void set_vertext(sfVertex vertex[4], game_assets_t *win,
    sfVector3f pr, wall_t *weapon)
{
    float z_add = pr.z * SIZE_WEAPON / SIZE_WALL;
    sfVector3f pr2 = {pr.x + z_add / 2.0, pr.y, pr.z};
    float left = weapon->weapon->rect.left;
    float top = weapon->weapon->rect.top;
    float width = weapon->weapon->rect.width;
    float height = weapon->weapon->rect.height;

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

static void draw(game_assets_t *win, wall_t *weapon)
{
    sfRenderStates st = {sfBlendAlpha, sfTransform_Identity,
        pack(weapon->texture, win->text_pack), NULL};

    sfVertexArray_setPrimitiveType(win->csfml.quad, sfQuads);
    sfRenderTexture_drawVertexArray(win->csfml.rend_text,
        win->csfml.quad, &st);
}

void display_weapon(game_assets_t *win, wall_t *weapon)
{
    sfVertex vertex[4] = {0};
    sfVector3f pt = {0};

    if (weapon == NULL || !weapon->weapon->is_attacking)
        return;
    pt = project_pt(win, weapon->pos1, &weapon->printbale);
    if (weapon->printbale != PRINTABLE)
        return;
    sfVertexArray_clear(win->csfml.quad);
    set_vertext(vertex, win, pt, weapon);
    for (size_t i = 0; i < 4; ++i)
        sfVertexArray_append(win->csfml.quad, vertex[i]);
    draw(win, weapon);
}
