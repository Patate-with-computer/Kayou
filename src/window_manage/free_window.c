/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** free_window.c
*/

#include "window_manage.h"
#include "map.h"
#include "player.h"
#include "lib.h"
#include "target.h"
#include "buttons.h"
#include "song_manage.h"
#include "texture_pack.h"
#include "echap_menu.h"
#include "cursor_bar.h"

static void free_other_csfml(game_assets_t *to_free)
{
    if (to_free->csfml.circle != NULL)
        sfCircleShape_destroy(to_free->csfml.circle);
    if (to_free->csfml.cursor_circle != NULL)
        sfCircleShape_destroy(to_free->csfml.cursor_circle);
    if (to_free->csfml.wp_shader != NULL)
        sfShader_destroy(to_free->csfml.wp_shader);
    if (to_free->csfml.back != NULL)
        sfSprite_destroy(to_free->csfml.back);
}

static void free_csfml(game_assets_t *to_free)
{
    if (to_free->csfml.clock != NULL)
        sfClock_destroy(to_free->csfml.clock);
    if (to_free->csfml.win != NULL)
        sfRenderWindow_destroy(to_free->csfml.win);
    if (to_free->csfml.quad != NULL)
        sfVertexArray_destroy(to_free->csfml.quad);
    if (to_free->csfml.shadow != NULL)
        sfShader_destroy(to_free->csfml.shadow);
    if (to_free->csfml.hover != NULL)
        sfShader_destroy(to_free->csfml.hover);
    if (to_free->csfml.font != NULL)
        sfFont_destroy(to_free->csfml.font);
    if (to_free->csfml.text != NULL)
        sfText_destroy(to_free->csfml.text);
    free_other_csfml(to_free);
}

game_assets_t *free_window(game_assets_t *to_free)
{
    if (to_free == NULL)
        return NULL;
    free_csfml(to_free);
    if (to_free->csfml.sprite != NULL)
        sfSprite_destroy(to_free->csfml.sprite);
    if (to_free->csfml.rend_text != NULL)
        sfRenderTexture_destroy(to_free->csfml.rend_text);
    if (to_free->csfml.light_shader != NULL)
        sfShader_destroy(to_free->csfml.light_shader);
    free_song(to_free->song_lib);
    destroy_menu_struct(to_free->menu);
    free_target(to_free->entities.target);
    free_player(to_free->entities.player);
    free_wall(to_free->entities.wall);
    free_texture_pack(to_free->text_pack);
    free_echap_menu(to_free->entities.echap_menu);
    free_cursors(to_free->entities.cursor);
    MY_FREE(to_free);
    return NULL;
}
