/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** display_horizon_bar.c
*/

#include <math.h>
#include "player.h"
#include "window/window_manage.h"
#include "map.h"
#include "ground_evt.h"

static void set_vertex(sfVertex vertex[4], sfVector3f pr, game_assets_t *win,
    sfColor color)
{
    vertex[0] = (sfVertex){.position = {0,
        add_to_vector(pr, pr.z, win).y},
        .color = color, .texCoords = {0, 0}};
    vertex[1] = (sfVertex){.position = {0,
        add_to_vector(pr, 0.0, win).y},
        .color = color, .texCoords = {0, 1}};
    vertex[2] = (sfVertex){.position = {win->size.x * win->scale.x,
        add_to_vector(pr, 0.0, win).y},
        .color = color, .texCoords = {1, 1}};
    vertex[3] = (sfVertex){.position = {win->size.x * win->scale.x,
        add_to_vector(pr, pr.z, win).y},
        .color = color, .texCoords = {0, 1}};
}

void display_horizon_bar(game_assets_t *win)
{
    sfVertex vertex[4] = {0};
    is_printable_t p = PRINTABLE;
    float angle = win->entities.player->angle;
    float dist = MAX_DIST_RENDER * !win->is_brume +
        MAX_REND_BRUME * win->is_brume;
    sfVector2f player = win->entities.player->pos;
    sfVector2f point = {
        player.x + cosf(angle) * dist, player.y + sinf(angle) * dist};
    sfVector3f pr = project_pt(win, point, &p);

    if (win->room == RM_SECRET)
        return;
    set_vertex(vertex, pr, win, sfBlack);
    sfVertexArray_clear(win->csfml.quad);
    for (int i = 0; i < 4; i++)
        sfVertexArray_append(win->csfml.quad, vertex[i]);
    sfRenderTexture_drawVertexArray(win->csfml.rend_text,
        win->csfml.quad, NULL);
}

#include "lib.h"
static void draw_bar(game_assets_t *win, sfVertex vertex[4], float dist)
{
    sfRenderStates st = {sfBlendAlpha, sfTransform_Identity,
        NULL, win->csfml.brume_shader};
    sfVector2f y_pos = {vertex[0].position.y, vertex[1].position.y};
    sfVector2f pos_pl = win->entities.player->pos;

    sfShader_setFloatUniform(win->csfml.brume_shader,
        "u_time", get_millis(win->csfml.clock) / 70.0);
    sfShader_setFloatUniform(win->csfml.brume_shader, "dist", dist);
    sfShader_setFloatUniform(win->csfml.brume_shader,
        "cam_angle", win->entities.player->angle);
    sfShader_setVec2Uniform(win->csfml.brume_shader, "w_size", win->size);
    sfShader_setVec2Uniform(win->csfml.brume_shader, "scale_win", win->scale);
    sfShader_setVec2Uniform(win->csfml.brume_shader, "y_pos", y_pos);
    sfShader_setVec2Uniform(win->csfml.brume_shader, "player_pos", pos_pl);
    sfVertexArray_clear(win->csfml.quad);
    for (int i = 0; i < 4; i++)
        sfVertexArray_append(win->csfml.quad, vertex[i]);
    sfVertexArray_setPrimitiveType(win->csfml.quad, sfQuads);
    sfRenderTexture_drawVertexArray(win->csfml.rend_text,
        win->csfml.quad, &st);
}

void display_one_bar(game_assets_t *win, float dist)
{
    sfVertex vertex[4] = {0};
    is_printable_t p = PRINTABLE;
    float angle = win->entities.player->angle;
    sfVector2f player = win->entities.player->pos;
    sfVector2f point = {
        player.x + cosf(angle) * dist,
        player.y + sinf(angle) * dist
    };
    sfVector3f pr = project_pt(win, point, &p);

    set_vertex(vertex, pr, win, sfWhite);
    draw_bar(win, vertex, dist);
}
