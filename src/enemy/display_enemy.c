/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** display_enemy.c
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "enemy.h"
#include "window_manage.h"
#include "map.h"
#include "player.h"
#include "texture_pack.h"
#include "lib.h"

static void set_vertext(sfVertex vertex[4], game_assets_t *win,
    sfVector3f pr, wall_t *enemy)
{
    float z_add = pr.z * SIZE_ENEMY / SIZE_WALL;
    sfVector3f pr2 = pr;
    float left = enemy->enemy->rect.left;
    float top = enemy->enemy->rect.top;
    float width = enemy->enemy->rect.width;
    float height = enemy->enemy->rect.height;

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
    print_life_str(win, enemy, pr);
}

static void set_enemy_shader(game_assets_t *win, wall_t *enemy)
{
    float angle = get_wall_visibility_angle(enemy, win->entities.player,
        win->entities.wall);
    bool visble = angle != -1;

    sfShader_setFloatUniform(win->csfml.shadow, "dist", enemy->distance);
    sfShader_setBoolUniform(win->csfml.shadow, "is_shadow", win->shadow_room);
    sfShader_setBoolUniform(win->csfml.shadow, "is_visible", visble);
    sfShader_setFloatUniform(win->csfml.shadow, "light_angle", angle);
}

static void draw(game_assets_t *win, wall_t *enemy)
{
    sfRenderStates st = {sfBlendAlpha, sfTransform_Identity,
        pack(enemy->texture, win->text_pack), win->csfml.shadow};

    sfVertexArray_setPrimitiveType(win->csfml.quad, sfQuads);
    sfRenderTexture_drawVertexArray(win->csfml.rend_text,
        win->csfml.quad, &st);
}

#include "lib.h"
static void wait_time_attack(game_assets_t *win, wall_t *enemy)
{
    if (get_distance(win->entities.player->pos, enemy->pos1) >=
        enemy_attack_list[enemy->texture.text_nb].max_dist)
        return;
    if (enemy->enemy->wait_time - get_millis(win->csfml.clock) <= 0) {
        if (!win->is_paused)
            add_an_attack(enemy, win);
        enemy->enemy->wait_time = get_millis(win->csfml.clock) +
            enemy_attack_list[enemy->texture.text_nb].reload_time +
            randint(MAX_TIME_ADD_TO_WAIT);
    }
}

void display_enemy(game_assets_t *win, wall_t *enemy)
{
    sfVertex vertex[4] = {0};
    sfVector3f pt = {0};

    if (enemy == NULL)
        return;
    move_an_enemy(win, enemy);
    if (win->shadow_room && enemy->distance >= MAX_SHADOW)
        return;
    pt = project_pt(win, enemy->pos1, &enemy->printbale);
    wait_time_attack(win, enemy);
    if (enemy->printbale != PRINTABLE)
        return;
    sfVertexArray_clear(win->csfml.quad);
    set_enemy_shader(win, enemy);
    set_vertext(vertex, win, pt, enemy);
    for (size_t i = 0; i < 4; ++i)
        sfVertexArray_append(win->csfml.quad, vertex[i]);
    draw(win, enemy);
}
