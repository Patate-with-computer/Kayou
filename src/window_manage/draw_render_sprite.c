/*
** EPITECH PROJECT, 2024
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** draw_render_sprite.c
*/

#include "window_manage.h"
#include "map.h"
#include "player.h"

#include "lib.h"
static void set_sprite(game_assets_t *win)
{
    sfRenderTexture_display(win->csfml.rend_text);
    sfSprite_setTexture(win->csfml.sprite,
        sfRenderTexture_getTexture(win->csfml.rend_text), sfTrue);
    sfSprite_setPosition(win->csfml.sprite, (sfVector2f){0, 0});
}

void display_rendertexture(game_assets_t *win)
{
    set_sprite(win);
    sfRenderWindow_drawSprite(win->csfml.win, win->csfml.sprite, NULL);
}
