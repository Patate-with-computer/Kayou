/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** init_screen_text.c
*/

#include "window/window_manage.h"
#include "screen_text.h"
#include "texture_pack.h"
#include "lib.h"

////////////////////////////////////////////////////////////
/// \brief function to set the vertex to then display them on the window
///
/// \param vertex[4] the array of vertex to set
/// \param mode the mode to set the txt (big for story txt and
///             litle to pnj txt)
/// \param win_size the size of the window
/// \param scale_y the scale y of the window to set corectly
///                the percent of the window
///
////////////////////////////////////////////////////////////
static void set_vertex(sfVertex vertex[4], size_t mode, sfVector2f win_size,
    float scale_y)
{
    float top_size = MARGIN_TOP_BIG;
    float left = MARGIN_LEFT;
    float bottom = MARGIN_BOTTOM;
    float size = SIZE_TEXTURE_SCREEN_TEXT;

    if (mode == LITLE_MODE)
        top_size = GET_SIZE(win_size.y, scale_y);
    vertex[0] = (sfVertex){.position = {left, top_size},
        .texCoords = {0, 0}, .color = sfWhite};
    vertex[1] = (sfVertex){.position = {win_size.x - left, top_size},
        .texCoords = {0, size}, .color = sfWhite};
    vertex[2] = (sfVertex){
        .position = {win_size.x - left, win_size.y - bottom},
        .texCoords = {size, size}, .color = sfWhite};
    vertex[3] = (sfVertex){.position = {left, win_size.y - bottom},
        .texCoords = {size, 0}, .color = sfWhite};
}

////////////////////////////////////////////////////////////
/// \brief function to draw the vertex in the screen
///
/// \param win the game assets struct
/// \param vertex[4] the array of vertex to set to the vertexArray
///
////////////////////////////////////////////////////////////
static void draw(game_assets_t *win, sfVertex vertex[4])
{
    sfTexture *texture = pack((set_texture_t){WALL_TYPE, W_TEXT_PANEL},
        win->text_pack);
    sfRenderStates st = {sfBlendAlpha, sfTransform_Identity, texture, NULL};

    sfVertexArray_clear(win->csfml.quad);
    for (size_t i = 0; i < 4; ++i)
        sfVertexArray_append(win->csfml.quad, vertex[i]);
    sfVertexArray_setPrimitiveType(win->csfml.quad, sfQuads);
    sfTransform_scale(&st.transform, win->scale.x, win->scale.y);
    sfRenderWindow_drawVertexArray(win->csfml.win, win->csfml.quad, &st);
}

void display_screen_text(game_assets_t *win, size_t mode, const char *txt)
{
    sfVertex vertex[4] = {0};

    if (txt != NULL) {
        win->is_paused = true;
        win->is_text = true;
        win->is_echap_menu = false;
        set_vertex(vertex, mode, win->size, win->scale.y);
        draw(win, vertex);
    }
    draw_txt(win, txt, mode);
}
