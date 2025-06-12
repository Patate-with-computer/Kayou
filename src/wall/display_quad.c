/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** display_quad.c
*/

#include "window/window_manage.h"
#include "map.h"
#include "player.h"
#include "texture_pack.h"
#include "lib.h"

sfVector2f add_to_vector(sfVector3f src, float y, game_assets_t *win)
{
    sfVector2f new_pos = {0.0, 0.0};
    float ar = win->entities.player->arrondie;

    new_pos.x = src.x + (float)win->size.x / 2.0;
    new_pos.y = (win->size.y - (float)POS(Y, TOADD) / win->scale.y);
    if (ar != 0)
        new_pos.y -= win->entities.player->focal / (src.y * ar);
    new_pos.y += src.y - y;
    new_pos.x *= win->scale.x;
    new_pos.y *= win->scale.y;
    return new_pos;
}

static void set_vertext(sfVertex vertex[4], game_assets_t *win,
    sfVector3f pr[2], wall_t *wall)
{
    vertex[0] = (sfVertex){
        .position = add_to_vector(pr[0], 0, win),
        .color = sfWhite,
        .texCoords = {wall->rect.x, 0.0}};
    vertex[3] = (sfVertex){
        .position = add_to_vector(pr[0], pr[0].z, win),
        .color = sfWhite,
        .texCoords = {wall->rect.x, (float)SIZE_TEXT(PLAYER)}};
    vertex[2] = (sfVertex){
        .position = add_to_vector(pr[1], pr[1].z, win),
        .color = sfWhite,
        .texCoords = {wall->rect.y, (float)SIZE_TEXT(PLAYER)}};
    vertex[1] = (sfVertex){
        .position = add_to_vector(pr[1], 0, win),
        .color = sfWhite,
        .texCoords = {wall->rect.y, 0.0}};
}

static void draw(game_assets_t *win, wall_t *wall)
{
    sfRenderStates st = {sfBlendAlpha, sfTransform_Identity,
        pack(wall->texture, win->text_pack), win->csfml.shadow};
    float angle = get_wall_visibility_angle(wall, win->entities.player,
        win->entities.wall);
    bool visble = angle != -1;

    sfShader_setFloatUniform(win->csfml.shadow, "dist", wall->distance);
    sfShader_setBoolUniform(win->csfml.shadow, "is_shadow", win->shadow_room);
    sfShader_setBoolUniform(win->csfml.shadow, "is_visible", visble);
    sfShader_setFloatUniform(win->csfml.shadow, "light_angle", angle);
    sfVertexArray_setPrimitiveType(win->csfml.quad, sfQuads);
    sfRenderTexture_drawVertexArray(win->csfml.rend_text,
        win->csfml.quad, &st);
}

void display_quad(game_assets_t *win, wall_t *wall)
{
    is_printable_t printable[2] = {PRINTABLE, PRINTABLE};
    sfVector3f pr[2] = {project_pt(win, wall->pos1, &printable[0]),
        project_pt(win, wall->pos2, &printable[1])};
    sfVertex vertex[4] = {0};

    if (printable[0] == NOT_PRINTABLE || printable[1] == NOT_PRINTABLE) {
        wall->printbale = NOT_PRINTABLE;
        return;
    }
    if (win->shadow_room && wall->distance >= MAX_SHADOW)
        return;
    wall->printbale = PRINTABLE;
    sfVertexArray_clear(win->csfml.quad);
    set_vertext(vertex, win, pr, wall);
    for (size_t i = 0; i < 4; ++i)
        sfVertexArray_append(win->csfml.quad, vertex[i]);
    draw(win, wall);
}
