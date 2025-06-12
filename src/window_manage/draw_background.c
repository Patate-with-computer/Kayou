/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** draw_background.c
*/

#include <math.h>
#include "window/window_manage.h"
#include "player.h"
#include "lib.h"

static void set_vertext(sfVertex vertex[4], sfVector3f pos,
    const sfColor color)
{
    vertex[0] = (sfVertex){
        .position = {0, pos.y},
        .color = color};
    vertex[1] = (sfVertex){
        .position = {0, pos.z},
        .color = color};
    vertex[2] = (sfVertex){
        .position = {pos.x, pos.z},
        .color = color};
    vertex[3] = (sfVertex){
        .position = {pos.x, pos.y},
        .color = color};
}

static void draw(game_assets_t *win, sfVertex vertex[4])
{
    sfVertexArray_clear(win->csfml.quad);
    for (size_t i = 0; i < 4; ++i)
        sfVertexArray_append(win->csfml.quad, vertex[i]);
    sfVertexArray_setPrimitiveType(win->csfml.quad, sfQuads);
    sfRenderTexture_drawVertexArray(win->csfml.rend_text,
        win->csfml.quad, NULL);
}

static sfColor rm_color(bool is_brume, sfColor src)
{
    float to_add = is_brume * 50.0f / 100.0f;
    sfColor new = src;

    new.r -= new.r * to_add;
    new.g -= new.g * to_add;
    new.b -= new.b * to_add;
    return new;
}

void draw_background(game_assets_t *win)
{
    sfVertex vertex[4] = {0};
    sfVector2f size = {win->size.x * win->scale.x, win->size.y * win->scale.y};
    sfVector3f pos1 = {size.x,
        (win->size.y - (float)POS(Y, TOADD) / win->scale.y) * win->scale.y,
        size.y};
    sfVector3f pos2 = {size.x, pos1.y, 0};

    if (win->shadow_room)
        return;
    set_vertext(vertex, pos2, rm_color(win->is_brume, roof_color));
    draw(win, vertex);
    set_vertext(vertex, pos1, rm_color(win->is_brume, floor_color));
    draw(win, vertex);
}
