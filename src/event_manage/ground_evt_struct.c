/*
** EPITECH PROJECT, 2025
** G-ING-210-PAR-2-1-wolf3d-tanguy.folliot
** File description:
** ground_evt_struct.c
*/

#include "ground_evt.h"

const ground_evt_t grd[] = {
    {set_hallway, {288, 320, 32, 32.0}, RM_INTRO, {RESET, RESET}},
    {set_intro, {-20.0, 0.0, 20.0, 64.0}, RM_HALLWAY, {270.0, 336.0}},
    {set_hallway1, {128, 0, 32, 64}, RM_HALLWAY, {RESET, RESET}},
    {set_intro, {-20.0, 0.0, 20.0, 64.0}, RM_HALLWAY_1, {270.0, 336.0}},
    {set_hallway2, {128, 0, 32, 64}, RM_HALLWAY_1, {RESET, RESET}},
    {set_intro, {-20.0, 0.0, 20.0, 64.0}, RM_HALLWAY_2, {270.0, 336.0}},
    {set_hallway, {128, 0, 32, 64}, RM_HALLWAY_2, {RESET, RESET}},
    {set_secret, {0, 260, 40, 20}, RM_INTRO, {RESET, RESET}},
    {set_intro, {-16, -20, 32, 20}, RM_SECRET, {16, 220}},
    {set_diag_map, {160, -140, 40, 40}, RM_HALLWAY_1, {RESET, RESET}},
    {set_hallway1, {-80, 160, 40, 40}, RM_DIAGMAP, {140, -120}},
    {set_labyrinth, {128, 288, 32, 32}, RM_DIAGMAP, {RESET, RESET}},
    {set_diag_map, {-120, 160, 40, 40}, RM_LABYRINTH, {144, 272}},
    {set_hell_room, {500, 0, 40, 40}, RM_LABYRINTH, {RESET, RESET}},
    {set_labyrinth, {-60, 40, 20, 40}, RM_HELL_ROOM, {410, 20}},
    {set_boss, {600, 800, 40, 40}, RM_HELL_ROOM, {RESET, RESET}},
    {set_hell_room, {0, 245, 32, 40}, RM_BOSS, {620, 780}},
    {NULL, {0.0, 0.0, 0.0, 0.0}, 0, {RESET, RESET}}
};
