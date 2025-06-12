/*
** EPITECH PROJECT, 2025
** Wolf3d
** File description:
** minimap.c
*/

#include <math.h>
#include "window/window_manage.h"
#include "player.h"
#include "map.h"
#include "enemy.h"

static void set_one_line(game_assets_t *assets, wall_t *wall)
{
    sfVertex vertex[2] = {
        {.color = sfWhite, .position = {wall->pos1.x, wall->pos1.y}},
        {.color = sfWhite, .position = {wall->pos2.x, wall->pos2.y}}
    };

    for (size_t i = 0; i < 2; ++i) {
        vertex[i].position.x -= assets->entities.player->pos.x;
        vertex[i].position.y -= assets->entities.player->pos.y;
        sfVertexArray_append(assets->csfml.quad, vertex[i]);
    }
    sfVertexArray_setPrimitiveType(assets->csfml.quad, sfLines);
}

static void set_all_lines(game_assets_t *win)
{
    wall_t *wall = win->entities.wall;

    for (; wall != NULL; wall = wall->next) {
        if (wall->object != IS_WALL || wall->hidden)
            continue;
        if (wall->distance >= SIZE_MINIMAP)
            break;
        if (win->shadow_room && wall->distance >= MAX_DIST_SHADOW)
            break;
        set_one_line(win, wall);
    }
}

void set_circle(sfCircleShape *circle, float radius,
    sfVector2f pos, sfColor color)
{
    sfCircleShape_setFillColor(circle, color);
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setOrigin(circle, (sfVector2f){radius, radius});
    sfCircleShape_setPosition(circle, pos);
}

static void print_item_minimap(game_assets_t *win, wall_t *wall,
    sfRenderStates st)
{
    sfVector2f pl_pos = win->entities.player->pos;

    if (wall->object != IS_ITEM)
        return;
    if (wall->item->pnj_txt == NULL || wall->distance >= SIZE_MINIMAP ||
        (win->shadow_room && wall->distance >= MAX_DIST_SHADOW))
        return;
    set_circle(win->csfml.circle, SIZE_ENEMY_MMP,
        (sfVector2f){wall->pos1.x - pl_pos.x, wall->pos1.y - pl_pos.y},
        (sfColor){50, 150, 200, 255});
    sfRenderWindow_drawCircleShape(win->csfml.win, win->csfml.circle, &st);
}

static void print_player_minimap(game_assets_t *win, sfRenderStates st)
{
    sfVector2f p0 = {0.0, 0.0};
    sfCircleShape *circle = win->csfml.circle;

    set_circle(circle, SIZE_MINIMAP + 8.0, p0, back_color);
    sfRenderWindow_drawCircleShape(win->csfml.win, circle, &st);
    set_circle(circle, SIZE_PLAYER, p0, player_color);
    sfRenderWindow_drawCircleShape(win->csfml.win, circle, &st);
}

static void print_circles(game_assets_t *win, sfRenderStates st)
{
    sfCircleShape *circle = win->csfml.circle;
    sfVector2f pl_pos = win->entities.player->pos;
    float radius[2] = {SIZE_ENEMY_MMP, SIZE_ATK_MMP};

    print_player_minimap(win, st);
    for (wall_t *wall = win->entities.wall; wall != NULL; wall = wall->next) {
        print_item_minimap(win, wall, st);
        if (wall->object != IS_ENEMY && wall->object != IS_ATTACK)
            continue;
        if (wall->distance >= SIZE_MINIMAP ||
            (win->shadow_room && wall->distance >= MAX_DIST_SHADOW))
            break;
        set_circle(circle, radius[wall->object == IS_ATTACK],
            (sfVector2f){wall->pos1.x - pl_pos.x, wall->pos1.y - pl_pos.y},
            enemies_color[wall->object == IS_ATTACK]);
        sfRenderWindow_drawCircleShape(win->csfml.win, circle, &st);
    }
}

void display_minimap(game_assets_t *assets)
{
    float a = assets->entities.player->angle;
    sfRenderStates st = {sfBlendAlpha, sfTransform_Identity,
        NULL, NULL};
    float pos_y = assets->size.y - SIZE_MINIMAP - 8.0;
    float pos_x = SIZE_MINIMAP + 8.0;
    sfVector2f scale = assets->scale;

    sfVertexArray_clear(assets->csfml.quad);
    set_all_lines(assets);
    sfTransform_translate(&st.transform, pos_x * scale.x, pos_y * scale.y);
    sfTransform_scale(&st.transform, assets->scale.x, assets->scale.y);
    sfTransform_rotate(&st.transform, -CONV_DEG(a) - 90.0);
    print_circles(assets, st);
    sfRenderWindow_drawVertexArray(assets->csfml.win,
        assets->csfml.quad, &st);
}
