/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** file_manage.h
*/

#ifndef FILE_MANAGE_H
    #define FILE_MANAGE_H
    #include <SFML/System/Vector2.h>
    #include <stdio.h>
    #include <stdbool.h>
    #define COMMENT_CHAR '#'
    #define WOLF_TERM ".wolf"
    #define PNG_TERM ".png"
    #define ROOM(a) ("assets/maps/" #a WOLF_TERM)
    #define SCAN_LINE "%f:%f-%f:%f:%c"
    #define SCAN_ENEMY "%f:%f-%f:%s"
    #define NBR_ELEMENT_ENEMY 4
    #define SCAN_POS "X %f Y %f"
    #define SCAN_TEXTURE "%s"
    #define NBR_ELEMENT 4
    #define WALL_THICKNESS 8


typedef struct scan_line_s {
    sfVector2f to_write[3];
    sfVector2f start;
    sfVector2f start1;
    sfVector2f start2;
    sfVector2f end;
    sfVector2f end1;
    sfVector2f end2;
    sfVector2f dd;
    float step;
    float a;
    bool hidden;
} scan_line_t;

void convert_file(const char *file_name, float step);
void scan_all_line(FILE *src, FILE *dest, float step);
void get_file_write_name(const char *src, char dest[BUFSIZ], const char *term);
void create_rectangle(scan_line_t *scan, FILE *dest);
void print_step(scan_line_t *scan, FILE *dest);
char *get_texture_name(char const *file_name, const char *texture_pack,
    const char *folder);

#endif
