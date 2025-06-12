/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** screen_text.h
*/

#ifndef WOLF_SCREEN_TEXT_
    #define WOLF_SCREEN_TEXT_
    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include "wolf/struct.h"

// text settings
    #define TEXT_SIZE 40.0f
    #define MARGIN_LEFT 20.0f
    #define MULT_FACT 1.5f
    #define MARGIN_TOP_BIG MARGIN_LEFT
    #define MARGIN_BOTTOM MARGIN_LEFT
    #define SIZE_LITLE(s) ((100.0f - (20.0f * s)) / 100.0f)
    #define GET_SIZE(a, scale) (a * SIZE_LITLE(scale))
    #define SIZE_TEXTURE_SCREEN_TEXT 32.0f
    #define TIME_TXT 20.0f
static const sfColor text_color = {200, 220, 200, 255};

enum {
    LITLE_MODE,
    BIG_MODE
};

enum {
    TALK,
    ADVANCE,
    QUIT
};

// dialog text
extern const char intro_txt[];
extern const char intro_pnj[];
extern const char intro_pnj_enemy[];
extern const char intro_command[];
extern const char lab_turn_pnj[];
extern const char good_ending[];
extern const char wrong_way[];
extern const char hello[];
extern const char dont_like[];
extern const char visibilty[];
extern const char plank[];
extern const char golDsquid[];
extern const char warning[];

// demo room
extern const char break_the_wall[];
extern const char there_is_shadow[];
extern const char there_is_fog[];
extern const char there_is_item[];
extern const char there_is_enemy[];
extern const char end_first_phase[];
extern const char end_second_phase[];
extern const char end_last_phase[];

////////////////////////////////////////////////////////////
/// \brief display one txt on the screen
///        to display the dialog for exemple
///
/// \param win the game assets
/// \param mode the mode to set the txt (big for story txt and
///             litle to pnj txt)
/// \param str the string to put
///
////////////////////////////////////////////////////////////
void display_screen_text(game_assets_t *win, size_t mode, const char *txt);

////////////////////////////////////////////////////////////
/// \brief set the text and get is size
///
/// The returned value is the size of the text after
/// it scale and and the str set
///
/// \param win the game assets
/// \param str the string to put
///
/// \return the size of the text
///
////////////////////////////////////////////////////////////
sfVector2f get_size_txt(game_assets_t *win, const char *str);

////////////////////////////////////////////////////////////
/// \brief function to draw text in the good position
///
/// \param win the game assets struct
/// \param txt the text to put
/// \param mode the mode to set the txt (big for story txt and
///             litle to pnj txt)
///
////////////////////////////////////////////////////////////
void draw_txt(game_assets_t *win, const char *txt, size_t mode);

////////////////////////////////////////////////////////////
/// \brief function to get the text to print
///
/// give the txt and other and that give you the buffer containing
/// the text to print (every TXT_TIME the buffer is more big)
/// \param prev_launch to set the print of the txt
/// \param txt the text to put
/// \param win the game assets struct
/// \return the buffer
////////////////////////////////////////////////////////////
char *get_buffer(const char *txt, bool *prev_launch, game_assets_t *win);

////////////////////////////////////////////////////////////
/// \brief draw the buffer line by line
///
/// \param win the game assets struct
/// \param buffer the buffer to display
/// \param mode the mode to set the txt (big for story txt and
///             litle to pnj txt)
////////////////////////////////////////////////////////////
void draw_all_lines(game_assets_t *win, char *buffer, size_t mode);

////////////////////////////////////////////////////////////
/// \brief put the text in the screen
///
/// \param win the game assets struct
/// \param txt the text to display in the window
/// \param mode the mode to set the txt (big for story txt and
///             litle to pnj txt)
/// \param nb_add the positon to put a line (iterable,
///                0 for the first pos, 1 tu put under 0 etc
///                its automatically calulated)
////////////////////////////////////////////////////////////
void put_the_txt(game_assets_t *win, const char *txt,
    size_t mode, size_t nb_add);

bool get_a_key(game_assets_t *win, size_t nb_key);

#endif
