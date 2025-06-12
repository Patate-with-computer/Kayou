/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** texture_pack.h
*/

#ifndef WOLF_TEXTURE_PACK
    #define WOLF_TEXTURE_PACK
    #define GET_ARRAY(a) (a##_texture_name)
    #define GET_FOLDER(a) (#a)
    #include <SFML/Graphics.h>
    #include <stdio.h>
    #include "wolf/type.h"

typedef struct game_assets_s game_assets_t;

// texture pack name
    #define MAX_TEXTURE_PACK 120
static const char texture_pack_dir[] = "./assets/texture_pack/";
void free_texture_name(char *texture_name[MAX_TEXTURE_PACK]);
char **get_texture_pack_name(void);


static const char default_pack[] = "default";

////////////////////////////////////////////////////////////
/// \brief array for the names of the texture (in assets/texture_pack/...)
////////////////////////////////////////////////////////////
extern const char *enemy_texture_name[];
extern const char *items_texture_name[];
extern const char *target_texture_name[];
extern const char *wall_texture_name[];
extern const char *weapon_texture_name[];
extern const char *attack_texture_name[];

////////////////////////////////////////////////////////////
/// \brief enum the match with the name of the texture (to
///        get the texture more easily)
////////////////////////////////////////////////////////////
enum {
    E_ENEMY, E_TENTACULE, E_MOB, E_CHEAT,
    E_WOOD};
enum {
    I_MONEY, I_LIFE, I_MANA, I_BARIL, I_EXPLOSION,
    I_PNJ, I_PNJ2, I_PNJ3, I_ENEMY, I_FLOWER,
    I_BLOOD, I_BLOOD2, I_BRICK};
enum {
    T_TARGET};
enum {
    W_WALL_1, W_WALL_2, W_WOOD, W_BUTTONS,
    W_SAVE_IMAGE, W_TEXT_SPRITE, W_CREDITS,
    W_BACKGROUND, W_TEXT_PANEL};
enum {
    WP_ROCK, WP_ROCK_VIEW,
    WP_LIGHT, WP_LIGHT_VIEW,
    WP_PISTOL, WP_PISTOL_VIEW,
    WP_BAG, WP_BAG_VIEW};
enum {
    A_YELLOW, A_BLUE, A_BLACK};

typedef struct texture_pack_s {
    sfTexture **enemy_text;
    sfTexture **items_text;
    sfTexture **target_text;
    sfTexture **weapon_text;
    sfTexture **wall_text;
    sfTexture **attack_text;
    sfTexture **credits_text;
} texture_pack_t;

size_t get_size_array(const char *array[]);
sfTexture **init_one_pack(const char *text_array[],
    const char *folder, const char *pack_name);
sfTexture **free_one_pack(sfTexture **pack);
texture_pack_t *init_texture_pack(const char *pack_name);
texture_pack_t *free_texture_pack(texture_pack_t *text_pack);
sfTexture *pack(set_texture_t set_text, texture_pack_t *text_pack);
sfVector2f get_texture_size(set_texture_t text, texture_pack_t *pk);
void load_text(game_assets_t *win, char const *text);
void set_all_wall_texture(game_assets_t *win);

#endif
